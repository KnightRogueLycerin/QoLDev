#ifndef WCI_HPP
#define WCI_HPP

//============================================================================
// Name        : Windows Consol Interface
// Author      : KnightRougeLycerin
// Version     : 1.0
// Copyright   : GNU GPLv3
// Description : User friendly windows console I/O
//============================================================================

#include <string>
#include <conio.h>
#include <iostream>
#include <Windows.h>

namespace wci{
    // Window Consol Colors
    enum Color {
			BLACK, DARK_BLUE, DARK_GREEN, DARK_TEAL, DARK_RED, PURPLE, BROWN,
			GRAY, DARK_GRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE
		};
    namespace implement{    // Implementation ment to left alone >:(
        // For use of SetConsoleTextAttribute(HANDLE, int)
        static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        // Color settings
        static Color C_Text(Color::WHITE);
        static Color C_Background(Color::BLACK);
        void commitColor(){
            int color =  (int)C_Background * 16 + (int)C_Text;
            SetConsoleTextAttribute(console, color);
        }
        void clearCin(){
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    } 
    /* Output */
    // Color
    void setColorDefault(){
        implement::C_Text = Color::WHITE; 
        implement::C_Background = Color::BLACK;
        implement::commitColor();
    };
    void setColor(const Color text, const Color background){
        implement::C_Text = text;
        implement::C_Background = background;
        implement::commitColor();
    };
    void setTextColor(const Color color = Color::WHITE){
        implement::C_Text = color;
        implement::commitColor();
    };
    void setBackgroundColor(const Color color = Color::BLACK){
        implement::C_Background = color;
        implement::commitColor();
    };
    // Text
    void out(const std::string& output, const bool& newline = true){
        if(newline)
            std::cout << output << std::endl;
        else
            std::cout << output;
    };
	void out(const std::string& output, const Color& text, const bool& newline = true){
        int c = implement::C_Text; 
        setTextColor(text);
        out(output, newline);
        setTextColor((Color)c);
    };
	void out(const std::string& output, const Color& text, const Color& background, const bool& newline = true){
        int ct = implement::C_Text; 
        int cb = implement::C_Background;
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
    };
    int in(char& input){
        char in = _getch();         // Input
        if (in == 0 || in == 0xE0)  // Sometimes needed twice
            in = _getch();
        wci::out(std::string(1,in));    // echo
        input = in;
	    return 0;
    };
    
    int in(int& input){
        int in = 0;
        std::cin >> in;
        if(std::cin.fail()){
            implement::clearCin();
            return -1;  // Did not obtain integer input
        }
        input = in;
        implement::clearCin();
        return 0;   // Obtained integer input
    };
    int in(float& input){
        float in = 0;
        std::cin >> in;
        if(std::cin.fail()){
            implement::clearCin();
            return -1;  // Did not obtain integer input
        }
        input = in;
        implement::clearCin();
        return 0;   // Obtained integer input
    };
    int in(double& input){
        double in = 0;
        std::cin >> in;
        if(std::cin.fail()){
            implement::clearCin();
            return -1;  // Did not obtain integer input
        }
        input = in;
        implement::clearCin();
        return 0;   // Obtained integer input
    };
    /* Misc */
    void clear(){
        COORD topLeft = { 0, 0 };
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(implement::console, &screen);
        FillConsoleOutputCharacterA(
            implement::console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        FillConsoleOutputAttribute(
            implement::console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        SetConsoleCursorPosition(implement::console, topLeft);
    };

    void wait(){
        unsigned char in = _getch();
        if (in == 0 || in == 0xE0)
            in = _getch();
    };

    void colorChart(){
        for (int i = 0; i <= 15; i++) {
             for (int j = 0; j <= 15; j++) {
                setColor((Color)j, (Color)i);
                out("########123********abc||||||||ABC%%%%%%%%");
            }
        }
    };
}
#endif // WCI_H