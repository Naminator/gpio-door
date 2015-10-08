#pragma once
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

    private:
        void ReloadSettings();
        json jsonSettings;
    };

}
