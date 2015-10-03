#pragma once
#include "stdafx.h"
#include "GarageDoor/Filesystem.h"

namespace GarageDoor {
namespace GPIO {

    class Pin
    {
    public:
        Pin(tstring);
        void SetValue(tstring);
        tstring GetValue();
        tstring GetRealValue();
        inline tstring GetName() { return this->name; }
        inline void Reset() { SetValue(this->defaultVal); }

    private:
        tstring name;
        tstring defaultVal;
        tstring currentVal;
    };

}
}
