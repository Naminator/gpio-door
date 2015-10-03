#pragma once
#include "stdafx.h"

namespace GarageDoor {
namespace GPIO {

    class Pin
    {
    public:
        Pin(tstring);
        void SetValue(tstring);
        tstring GetValue();

    private:
        tstring name;
        tstring defaultVal;
        tstring currentVal;
    };

}
}
