#include "GarageDoor/Console.h"

namespace GarageDoor {
namespace Console {

    void SetTitle(tstring title)
    {
#ifdef _WIN32
        SetConsoleTitle(title.c_str());
#elif __linux
        char esc_start[] = { 0x1b, ']', '0', ';', 0 };
        char esc_end[] = { 0x07, 0 };

        std::cout << esc_start << title << esc_end;
#endif
    }

    void WriteLine(tstring line)
    {
        std::cout << line << std::endl;
    }

    void FillRow(tchar symbol)
    {
        for(int i = 0; i < 80; i++)
        {
            std::cout << symbol;
        }

        std::cout << std::endl;
    }

}
}
