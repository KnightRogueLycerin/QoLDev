#pragma once

#include <string>

// Windows Consol Interface
namespace wci{
    // Window Consol Colors
    typedef enum Color {
			BLACK, DARK_BLUE, DARK_GREEN, DARK_TEAL, DARK_RED, PURPLE, BROWN,
			GREY, DARK_GREY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE
		};
    // Misc
    void clear();

    void wait();

    void colorChart();
    
    // Output
    void out(const std::string& output, const bool& newline = true);
	void out(const std::string& output, const Color& color, const bool& newline = true);

    void setColorDefault();
    void setColor(const Color text, const Color background);
    void setTextColor(const Color color = Color::WHITE);
    void setBackgroundColor(const Color color = Color::BLACK);
    

    // Input
    bool in(std::string& input);
}