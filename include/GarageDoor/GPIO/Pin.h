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
        void SetDirection(tstring);
        tstring GetValue();
        tstring GetRealValue();
        tstring GetDirection();
        inline tstring GetName() { return this->name; }
        inline void Reset() { SetValue(this->defaultVal); }
        inline bool HasErrors() { return (currentVal == "error"); }

    private:
        tstring name;
        tstring defaultVal;
        tstring currentVal;
        tstring directionVal;
        static const tstring SYSFS_PATH;

        tstring GetSysfsPath();
        tstring GetSysfsPath(tstring);
    };

}
}
