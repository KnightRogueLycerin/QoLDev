//============================================================================
// Name        : My Quality of Life Development
// Author      : Johan 'KnightRougeLycerin' Åhlander
// Version     : 0.01
// Copyright   : GNU GPLv3
// Description : Libraries for QoL
//============================================================================

#include "WCI.hpp"

int main() {
    // Datablock
    int err;
    std::string s;
    // Color & out test
    wci::setTextColor(wci::TEAL);
    wci::out("Hello ", false);
    wci::out("World", wci::GREEN, false);
    wci::out("!");
    wci::out("////////////", wci::BLACK, wci::YELLOW);
    wci::wait();
    // In & clear test
    wci::clear();
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
    wci::wait();

    return 0;
}