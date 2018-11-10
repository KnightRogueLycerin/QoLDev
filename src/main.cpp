//============================================================================
// Name        : My Quality of Life Development
// Author      : Johan 'KnightRougeLycerin' Åhlander
// Version     : 0.01
// Copyright   : GNU GPLv3
// Description : Libraries for QoL
//============================================================================

#include "WCI.hpp"

void wait_next(bool end){
    if(!end)
        wci::out("\nPress any key to coninue testing...", wci::DARK_GREY);
    else
        wci::out("\nPress any key to complete testing...", wci::DARK_GREY);
    wci::wait();
    wci::clear();
}

int main() {
    // Datablock
    char c;
    int err, integer;
    float floating;
    double real;
    std::string s;
    if(false){  // Color, out, & wait test 
        wci::out("\tCOLOR, WCI::OUT, & WAIT TEST\n", wci::DARK_TEAL);

        wci::setTextColor(wci::TEAL);
        wci::out("Hello ", false);
        wci::out("World", wci::GREEN, false);
        wci::out("!");
        wci::out("////////////", wci::BLACK, wci::YELLOW);
        
        wait_next(false);
    }

    if(true){   // In char tests
    wci::out("\tIN(CHAR) TEST\n", wci::DARK_TEAL);
        
        for(int i = 0; i < 3; i++){
            wci::out("Input char: ", false);
            wci::in(c);
            wci::out("You wrote: ", false);
            wci::out(std::string(1, c), wci::GREEN);
        }
        
        wait_next(false);
    }

    if(true){   // In int tests
    wci::out("\tIN(INT) TEST\n", wci::DARK_TEAL);

        for(int i = 0; i < 3; i++){
            wci::out("Input integer number: ", false);
            err = wci::in(integer);
            if(err == 0){
                wci::out("You wrote: ", false);
                if(integer < 0)
                    wci::out(std::to_string(integer), wci::PURPLE);
                else
                    wci::out(std::to_string(integer), wci::GREEN);
            }
            else{
                wci::out("ERR[" + std::to_string(err) + "] That's is not a integer number!", wci::RED);
            }
        }
        
        wait_next(false);
    }

    if(true){   // In float tests
    wci::out("\tIN(FLOAT) TEST\n", wci::DARK_TEAL);

        for(int i = 0; i < 3; i++){
            wci::out("Input float number: ", false);
            err = wci::in(floating);
            if(err == 0){
                wci::out("You wrote: ", false);
                if(floating < 0)
                    wci::out(std::to_string(floating), wci::PURPLE);
                else
                    wci::out(std::to_string(floating), wci::GREEN);
            }
            else{
                wci::out("ERR[" + std::to_string(err) + "] That's is not a float number!", wci::RED);
            }
        }
        
        wait_next(false);
    }

    if(true){   // In double tests
    wci::out("\tIN(DOUBLE) TEST\n", wci::DARK_TEAL);

        for(int i = 0; i < 3; i++){
            wci::out("Input 'double' number: ", false);
            err = wci::in(real);
            if(err == 0){
                wci::out("You wrote: ", false);
                if(real < 0)
                    wci::out(std::to_string(real), wci::PURPLE);
                else
                    wci::out(std::to_string(real), wci::GREEN);
            }
            else{
                wci::out("ERR[" + std::to_string(err) + "] That's is not a double number!", wci::RED);
            }
        }
        
        wait_next(false);
    }

    if(false){ // In std::string test
    wci::out("\tIN(STRING) TEST\n", wci::DARK_TEAL);
        
        wci::setColorDefault();
        wci::out("Please write as string with spaces!\nInput:", false);
        err = wci::in(s);
        if(err != 0){
            wci::out("Failure to input a string line -> wci::in(string&) with exit code: " + std::to_string(err), wci::RED);
            wci::wait();
            return -1;
        }
        wci::out("Thank you!", wci::GREEN);
        wci::wait();
        wci::out("You wrote:", false);
        wci::out(s, wci::TEAL);
        
        wait_next(false);
    }

    wci::out("\tThank you for participating!", wci::PINK);
    wait_next(true);
    return 0;
}