#pragma once
#include <exception>
#include "stdafx.h"
#include "GarageDoor/Filesystem.h"
#include "nlohmann/json/json.hpp"

using json = nlohmann::json;

namespace GarageDoor {

    class Config
    {
    public:
        Config();
        tstring GetSetting(tstring);
        json & GetJsonRaw();

    private:
        void ReloadSettings();
        json jsonSettings;
    };

}
