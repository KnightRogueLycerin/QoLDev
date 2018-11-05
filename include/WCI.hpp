#pragma once

#include <string>

// Windows Consol Interface
namespace wci{
    // Window Consol Colors
    typedef enum TextColor {
			BLACK, DARK_BLUE, DARK_GREEN, DARK_TEAL, DARK_RED, PURPLE, BROWN,
			GREY, DARK_GREY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE
		}TC;
    // Misc
    void clear();

    void ColorChart();
    
    // Output
    void out(const std::string& output, const bool& newline = true);

    // Input
    bool in(std::string& input);
}