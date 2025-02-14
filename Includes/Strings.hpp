#ifndef STRINGS_HPP
#define STRINGS_HPP

#include "CTRPluginFramework.hpp"
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <types.h>

namespace CTRPluginFramework
{
    std::string     Hex(u8 x);
    std::string     Hex(u16 x);
    std::string     Hex(u32 x);
    std::string     Hex(u64 x);
    std::string     Hex(float x);
    std::string     Hex(double x);
    bool ReadLine(CTRPluginFramework::File& file, std::string& line);
}

#endif