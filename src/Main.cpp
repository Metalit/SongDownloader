#include <chrono>

#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "custom-types/shared/register.hpp"

#include "questui/shared/QuestUI.hpp"

#include "songloader/shared/API.hpp"

#include "CustomLogger.hpp"
#include "ModConfig.hpp"

#include "CustomTypes/DownloadSongsFlowCoordinator.hpp"

#include "WebUtil.hpp"

#include "BeatSaverAPI.hpp"

ModInfo modInfo;

Logger& getLogger() {
    static auto logger = new Logger(modInfo, LoggerOptions(false, true)); 
    return *logger; 
}

DEFINE_CONFIG(ModConfig);

extern "C" void setup(ModInfo& info) {
    modInfo.id = "SongDownloader";
    modInfo.version = VERSION;
    info = modInfo;
    getModConfig().Init(modInfo);
}

extern "C" void load() {
    LOG_INFO("Starting SongDownloader installation...");
    il2cpp_functions::Init();
    QuestUI::Init();
    custom_types::Register::RegisterTypes<SongDownloader::DownloadSongsOptionsViewController, SongDownloader::DownloadSongsSearchViewController, SongDownloader::DownloadSongsFlowCoordinator>();
    QuestUI::Register::RegisterModSettingsFlowCoordinator<SongDownloader::DownloadSongsFlowCoordinator*>(modInfo);
    LOG_INFO("Successfully installed SongDownloader!");
}