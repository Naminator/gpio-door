#pragma once
#include "stdafx.h"

namespace GarageDoor {
namespace Filesystem {

    std::vector<std::string> ListDirectory(tstring);
    tstring ReadFile(tstring);
    void WriteFile(tstring, tstring);
}
}
