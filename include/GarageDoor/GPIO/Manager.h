#pragma once
#include "stdafx.h"
#include "GarageDoor/GPIO/Pin.h"
#include "GarageDoor/Filesystem.h"

typedef std::shared_ptr<GarageDoor::GPIO::Pin> pin_ptr;
typedef std::vector<pin_ptr> pin_map;
typedef std::shared_ptr<pin_map> pin_map_ptr;

namespace GarageDoor {
namespace GPIO {

    class Manager
    {
    public:
        Manager();
//        ~Manager();
        void LoadPins();
    private:
        pin_map pinList;
    };

}
}
