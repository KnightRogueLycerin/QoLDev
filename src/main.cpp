//============================================================================
// Name        : My Quality of Life Development
// Author      : Johan 'KnightRougeLycerin' Åhlander
// Version     : 0.01
// Copyright   : GNU GPLv3
// Description : Libraries for QoL
//============================================================================

#include "WCI.hpp"

int main() {
    wci::setTextColor(wci::TEAL);
    wci::out("Hello ", false);
    wci::out("World", wci::GREEN, false);
    wci::out("!");
    wci::out("////////////", wci::BLACK, wci::YELLOW);
    wci::wait();
}