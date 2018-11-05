#include "WCI.hpp"

#include <iostream>
#include <Windows.h>

namespace wci{
    /* Misc */
    // For use of SetConsoleTextAttribute()
    static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    /* Output */
    void out(const std::string& output, const bool& newline){
        std::string out = (newline) ? output + "\n" : output;
        std::cout << out;
    }

    /* Input */
}