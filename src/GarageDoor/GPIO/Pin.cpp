#include "GarageDoor/GPIO/Pin.h"

GarageDoor::GPIO::Pin::Pin(tstring name)
{
    this->name = name;
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
