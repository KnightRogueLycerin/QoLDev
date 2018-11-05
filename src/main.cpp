//============================================================================
// Name        : My Quality of Life Development
// Author      : Johan 'KnightRougeLycerin' Åhlander
// Version     : 0.0
// Copyright   : GNU GPLv3
// Description : Environment to work with Saab work application test
//============================================================================

#include "WCI.hpp"

int main() {
    wci::setColorDefault();
    wci::out("Hello ", false);
    wci::out("World", wci::Color::DARK_GREEN, false);
    wci::out("!");
    wci::wait();
}