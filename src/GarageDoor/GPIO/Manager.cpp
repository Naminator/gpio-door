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

void GarageDoor::GPIO::Manager::UnloadPins()
{
    if (pinList.size() < 1) { return; }

    std::cout << "Unloading pins..." << std::endl;

    for (pin_ptr & ptr : pinList)
    {
        ptr->Reset();
    }

    pinList.clear();
}

int GarageDoor::GPIO::Manager::CountPins()
{
    return pinList.size();
}

pin_ptr GarageDoor::GPIO::Manager::GetPin(tstring pinName)
{
    if (pinList.size() < 1) { return nullptr; }

    for (auto & i : pinList)
    {
        if ( i->GetName() == pinName )
        {
            return i;
        }
    }

    return nullptr;
}
