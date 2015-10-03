#pragma once

// C Runtime
#include <stdlib.h>
#include <malloc.h>
#include <memory>
#include <math.h>

// C++11 Runtime
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

// Project Constants
#include "constants.h"

// Boost Includes, if any


// Linux Runtime
#ifdef __linux
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#endif
