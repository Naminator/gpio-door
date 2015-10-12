#include "GarageDoor/Config.h"

GarageDoor::Config::Config()
{
    ReloadSettings();
}

void GarageDoor::Config::ReloadSettings()
{
    tstring jsonFile = GarageDoor::Filesystem::ReadFile("./settings.json");
    if (jsonFile.empty())
    {
        std::cerr << "Could not open settings.json. Make sure it exists!" << std::endl;
        exit(EXIT_FAILURE);
    }

    jsonSettings = json::parse(jsonFile);
    std::cout << "Settings.json Parsed" << std::endl;
}

tstring GarageDoor::Config::GetSetting(tstring key)
{
    tstring val;

    try
    {
        json jsonVal = jsonSettings[key];
        val = jsonVal.get<tstring>();
    } catch(std::exception e)
    {
        std::cout << "Unknown setting '" << key << "'" << std::endl;
        exit(EXIT_FAILURE);
    }

    return val;
}

json & GarageDoor::Config::GetJsonRaw()
{
    return std::ref(jsonSettings);
}
