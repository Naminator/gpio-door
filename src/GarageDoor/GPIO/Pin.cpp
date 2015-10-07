#include "GarageDoor/GPIO/Pin.h"

const tstring GarageDoor::GPIO::Pin::SYSFS_PATH = "/sys/class/gpio_sw/";

GarageDoor::GPIO::Pin::Pin(tstring name)
{
    this->name = name;
    this->currentVal = GetRealValue();

    std::cout << "Pin '" << name << "' registered with value " << currentVal << std::endl;
}

tstring GarageDoor::GPIO::Pin::GetValue()
{
    return currentVal;
}

tstring GarageDoor::GPIO::Pin::GetRealValue()
{
    tstring path = GetSysfsPath("data");
    currentVal = GarageDoor::Filesystem::ReadFile(path);

    return currentVal;
}

void GarageDoor::GPIO::Pin::SetValue(tstring value)
{
    tstring path = GetSysfsPath("data");
    currentVal = value;

    GarageDoor::Filesystem::WriteFile(path, value);
}

void GarageDoor::GPIO::Pin::SetDirection(tstring direction)
{
    tstring path = GetSysfsPath("cfg");
    GarageDoor::Filesystem::WriteFile(path, direction);
}

tstring GarageDoor::GPIO::Pin::GetDirection()
{
    tstring path = GetSysfsPath("cfg");
    return GarageDoor::Filesystem::ReadFile(path);
}

tstring GarageDoor::GPIO::Pin::GetSysfsPath()
{
    return SYSFS_PATH + name + "/";
}

tstring GarageDoor::GPIO::Pin::GetSysfsPath(tstring location)
{
    tstring sysfsPath = GetSysfsPath();
    return sysfsPath + location;
}
