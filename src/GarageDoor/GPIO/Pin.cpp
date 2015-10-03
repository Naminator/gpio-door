#include "GarageDoor/GPIO/Pin.h"

GarageDoor::GPIO::Pin::Pin(tstring name, tstring defVal)
{
    this->name = name;
    defaultVal = defVal;
}

tstring GarageDoor::GPIO::Pin::GetValue()
{
    return currentVal;
}

void GarageDoor::GPIO::Pin::SetValue(tstring value)
{
    currentVal = value;
    // TODO: Execute call to the pin
}
