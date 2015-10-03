#include "GarageDoor/GPIO/Manager.h"

GarageDoor::GPIO::Manager::Manager()
{
    LoadPins();
}

void GarageDoor::GPIO::Manager::LoadPins()
{
    std::string path = "/sys/class/gpio_sw";
    std::vector<std::string> dirList = GarageDoor::Filesystem::ListDirectory(path);

    std::cout << "Dirs found: " << dirList.size() << std::endl;
}
