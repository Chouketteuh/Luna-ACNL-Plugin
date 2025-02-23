#include "Strings.hpp"

namespace CTRPluginFramework
{
    std::string	Hex(u8 x)
    {
        char  buffer[3];

        sprintf(buffer, "%02X", x);
        return (std::string(buffer));
    }

    std::string	Hex(u16 x)
    {
        char  buffer[5];

        sprintf(buffer, "%04X", x);
        return (std::string(buffer));
    }

    std::string	Hex(u32 x)
    {
        char  buffer[9];

        sprintf(buffer, "%08X", x);
        return (std::string(buffer));
    }

    std::string	Hex(u64 x)
    {
        char  buffer[17];

        sprintf(buffer, "%016llX", x);
        return (std::string(buffer));
    }

    std::string	Hex(float x)
    {
        char  buffer[9];

        sprintf(buffer, "%08X", (u32)x);
        return (std::string(buffer));
    }

    std::string	Hex(double x)
    {
        char  buffer[17];

        sprintf(buffer, "%016llX", (u64)x);
        return (std::string(buffer));
    }

    // Function to read the entire text file
    std::string ReadWholeTxtFile(std::string Filepath)
    {
        File file(Filepath.c_str());
        char* buf = static_cast<char*>(::operator new(file.GetSize()));
        file.Read(buf, file.GetSize());
        std::string out(buf, file.GetSize());
        ::operator delete(buf);
        return out;
    }
}
