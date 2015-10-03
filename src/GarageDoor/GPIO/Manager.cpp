#include "GarageDoor/GPIO/Manager.h"

void GarageDoor::GPIO::Manager::LoadPins()
{
    std::string path = "/sys/class/gpio_sw";
    std::vector<std::string> dirList = GarageDoor::Filesystem::ListDirectory(path);

    for ( auto & i : dirList)
    {
        if (i == "standby_led" || i == "normal_led")
        {
            continue;
        }

        // Create instance of PIN and pushback
        pin_ptr pin(new GarageDoor::GPIO::Pin(i));
        pinList.push_back(pin);
    }
}

int GarageDoor::GPIO::Manager::CountPins()
{
    return pinList.size();
}
