#include "WCI.hpp"

#include <conio.h>
#include <iostream>
#include <Windows.h>

namespace wci{
    /* Misc */
    // For use of SetConsoleTextAttribute(HANDLE, int)
    static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clears the console and put the print pointer in the upper left corner
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
        if(newline)
            std::cout << output << std::endl;
        else
            std::cout << output;
    }
    void out(const std::string& output, const Color& text, const bool& newline){
        int c = C_Text; 
        setTextColor(text);
        out(output, newline);
        setTextColor((Color)c);
    }
    void out(const std::string& output, const Color& text, const Color& background, const bool& newline){
        int ct = C_Text; int cb = C_Background; 
        setColor(text, background);
        out(output, newline);
        setColor((Color)ct, (Color)cb);
    }


    /* Input */
    int in(std::string& input){
        input.clear();
        std::getline(std::cin, input);
        if(std::cin)
            return 0;       // successful operation
        else
            if(std::cin.eof())
                return -1;  // eof error
            else
                return -2;  // Other kind of failure
    }
    int in(char& input) {
        char in = _getch();         // Input
        if (in == 0 || in == 0xE0)  // Sometimes needed twice
            in = _getch();
        wci::out(std::string(1,in));    // echo
        input = in;
	    return 0;
    }
    void clearCin(){
            std::cin.clear();
            std::cin.ignore(256, '\n');
    }
    int in(int& input){
        int in = 0;
        std::cin >> in;
        if(std::cin.fail()){
            clearCin();
            return -1;  // Did not obtain integer input
        }
        input = in;
        clearCin();
        return 0;   // Obtained integer input
    }
    int in(float& input){
        float in = 0;
        std::cin >> in;
        if(std::cin.fail()){
            clearCin();
            return -1;  // Did not obtain float input
        }
        input = in;
        clearCin();
        return 0;   // Obtained float input
    }
    int in(double& input){
        double in = 0;
        std::cin >> in;
        if(std::cin.fail()){
            clearCin();
            return -1;  // Did not obtain double input
        }
        input = in;
        clearCin();
        return 0;   // Obtained double input
    }
}
