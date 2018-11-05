# QoLDev
*Personal liberies for Quality of Life Development*

**Content**
1. Usable
1. Development
1. Known Issues
1. Planded
1. Notes
1. Style Guide

# Usable 

# Development
## WCI.hpp
*Windows Console Interface*
* This library is made to get the moste out of the windos console in an user friendly way
* using `wci` namespace
* Colors: BLACK, DARK_BLUE, DARK_GREEN, DARK_TEAL, DARK_RED, PURPLE, BROWN,	GREY, DARK_GREY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, and WHITE
* Colors work with states, when you set a color it stay that way until another is set
### Misc
* **`void clear()`**
    * Clears the console window
* **`void wait()`**
    * Wait for input before coninuing code
    * **Not** `System("pause")`!!
* **`void colorChart()`**
    * Print a chart in the console over all 256 color combinations
### Output
* **`void out(const std::string& output, const bool& newline = true)`**
    * Print a string to the console, with or without a newline
* **`void out(const std::string& output, const Color& text, const bool& newline = true)`**
    * Same as above `out`-function with added color
    * The color is temporary and will revert to what ever it's set to before the call 
* **`void out(const std::string& output, const Color& text, const Color& background, const bool& newline = true)`**
    * Same as the `out`-function above, though this also change text background color

* **`void setColorDefault()`**
    * Sets the colors to white text on black background
* **`void setColor(const Color text, const Color background)`**
    * Change what the active output colors are
* **`void setTextColor(const Color color = Color::WHITE)`**
    * Spesificly change the active text color
* **`void setBackgroundColor(const Color color = Color::BLACK)`**
    * Spesificly change the active background color

### Input
* **`bool in(std::string& input)`**
    * Not done


# Known Issues
* Nothing is in a usable state

# Planed
## File
*A liberay that make it easy to interface with files*

# Notes
* Implimentation will be moved to the header once it's in a usable state

# Style Guide
## Libery Name
*Abbreviation explanation*
* General information
* Such as namespace
### Structural divitions
* **`Function`**
    * Function explenation
* **`Function`**
    * Function explenation