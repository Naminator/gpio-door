#include "GarageDoor/GPIO/Manager.h"

GarageDoor::GPIO::Manager::Manager()
{
    Config = new GarageDoor::Config();
}

GarageDoor::GPIO::Manager::Manager(GarageDoor::Config * conf) : Config(conf) {}

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
        if (!ptr->HasErrors())
        {
            ptr->Reset();
        }
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

void GarageDoor::GPIO::Manager::LoadDoors()
{
    json settings = Config->GetJsonRaw();

    for (auto door : settings["pin_mapping"]["doors"])
    {
        GarageDoor::Door doorStruct;
        doorStruct.name = door["name"].dump();
        doorStruct.pin = door["relay_pin"].dump();
        doorStruct.sig_key = door["sig_key"].dump();

        pin_ptr pin(GetPin(doorStruct.pin));
        if (pin != nullptr)
        {
            doorStruct.value = GetPin(doorStruct.pin)->GetValue();
        }

        doorList.insert(std::pair<tstring, GarageDoor::Door>(doorStruct.name, doorStruct));
        std::cout << "Appending door: " << doorStruct.name << std::endl;
    }

    std::cout << doorList.size() << " Door(s) Loaded From Configuration" << std::endl;
}
