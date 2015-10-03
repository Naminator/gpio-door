#include "GarageDoor/GPIO/Manager.h"

GarageDoor::GPIO::Manager::Manager()
{
    LoadPins();
}

void GarageDoor::GPIO::Manager::LoadPins()
{
    std::string path = "/sys/class/gpio_hw";

    DIR *dir = opendir(path.c_str());
    struct dirent *entry = readdir(dir);

    std::cout << "read read read" << std::endl;

    while(entry != null)
    {
        std::cout << entry->d_name << std::endl;
        delete entry;
        entry = readdir(dir);
    }

    closedir(dir);
}
