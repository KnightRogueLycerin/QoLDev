#include "WCI.hpp"

#include <conio.h>
#include <iostream>
#include <Windows.h>

namespace wci{
    /* Misc */
    // For use of SetConsoleTextAttribute(HANDLE, int)
    static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clears the consol and put the print pointer in the upper left corner
    void clear(){
        COORD topLeft = { 0, 0 };
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        SetConsoleCursorPosition(console, topLeft);
    }

    // Wait for any input before continuing
    void wait(){
        unsigned char in = _getch();
	if (in == 0 || in == 0xE0)
		in = _getch();
    }

    // Print a chart over all the possible colors in the windows console
    void colorChart(){
        for (int i = 0; i <= 15; i++) {
             for (int j = 0; j <= 15; j++) {
                setColor((Color)j, (Color)i);
                out("########123********abc||||||||ABC%%%%%%%%");
            }
        }
    }

    /* Output */
    // Colors
    static int C_Text((int)Color::WHITE), C_Background((int)Color::BLACK);
    void commitColor(){
        int color =  C_Background * 16 + C_Text;
        SetConsoleTextAttribute(console, color);
    }
    void setColorDefault(){
        C_Text = (int)Color::WHITE; C_Background = (int)Color::BLACK;
        commitColor();
    }
    void setColor(const Color text, const Color background){
        C_Text = (int)text; C_Background = (int)background;
        commitColor();
    }
    void setTextColor(const Color color){
        C_Text = (int)color;
        commitColor();
    }
    void setBackgroundColor(const Color color){
        C_Background = (int)color;
        commitColor();
    }
    // Text
    void out(const std::string& output, const bool& newline){
        std::string out = (newline) ? output + "\n" : output;
        std::cout << out;
    }
    void out(const std::string& output, const Color& color, const bool& newline){
        int c = C_Text; 
        setTextColor(color);
        out(output, newline);
        setTextColor((Color)c);
    }

    /* Input */
    bool in(std::string& input){
        input = "Not done yet!";
        return false;
    }
}