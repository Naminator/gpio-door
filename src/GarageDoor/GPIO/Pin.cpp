#include "GarageDoor/GPIO/Pin.h"

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
    tstring path = "/sys/class/gpio_sw/" + name + "/data";
    currentVal = GarageDoor::Filesystem::ReadFile(path);

    return currentVal;
}

void GarageDoor::GPIO::Pin::SetValue(tstring value)
{
    currentVal = value;
    // TODO: Execute call to the pin
}
