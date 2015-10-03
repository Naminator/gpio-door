#include "GarageDoor/GPIO/Manager.h"

void GarageDoor::GPIO::Manager::LoadPins()
{
    std::string path = "/sys/class/gpio_sw";
    std::vector<std::string> dirList = GarageDoor::Filesystem::ListDirectory(path);

    for ( auto & i : dirList)
    {
        std::cout << i << std::endl;
    }
}
