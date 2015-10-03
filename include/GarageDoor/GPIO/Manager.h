#pragma once
#include "stdafx.h"
#include "GarageDoor/GPIO/Pin.h"

typedef shared_ptr<GarageDoor::GPIO::Pin> pin_ptr;
typedef std::vector<pin_ptr> pin_map;
typedef shared_ptr<pin_map> pin_map_ptr;

namespace GarageDoor {
namespace GPIO {

    class Manager
    {
    public:
        Manager();
        ~Manager();

    private:
        void LoadPins();
        pin_map pinList;
    };

}
}
