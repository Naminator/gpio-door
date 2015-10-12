#pragma once
#include "stdafx.h"
#include "GarageDoor/GPIO/Pin.h"
#include "GarageDoor/Filesystem.h"
#include "GarageDoor/Config.h"
#include "GarageDoor/Door.h"
#include "nlohmann/json/json.hpp"

typedef std::shared_ptr<GarageDoor::GPIO::Pin> pin_ptr;
typedef std::vector<pin_ptr> pin_map;
typedef std::shared_ptr<pin_map> pin_map_ptr;
typedef std::map<tstring, GarageDoor::Door> door_map;

using json = nlohmann::json;

namespace GarageDoor {
namespace GPIO {

    class Manager
    {
    public:
        Manager();
        Manager(GarageDoor::Config*);
        void LoadPins();
        void UnloadPins();
        int CountPins();
        void LoadDoors();
        pin_ptr GetPin(tstring);

    private:
        pin_map pinList;
        door_map doorList;
        GarageDoor::Config * Config;
    };

}
}
