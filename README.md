# QoLDev
*Personal liberies for Quality of Life Development*

**Content**
1. Usable
1. Development
1. Known Issues
1. Planned
1. Notes
1. Style Guide

# Usable 
## WCI.hpp
*Windows Console Interface*
* This library is made to get the most out of the windows console in an user friendly way
* Using `wci` namespace
* Colors: BLACK, DARK_BLUE, DARK_GREEN, DARK_TEAL, DARK_RED, PURPLE, BROWN, GREY, DARK_GREY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, and WHITE
* Colors work with states, when you set a color it stay that way until another is set
### Misc
* **`void clear()`**
    * Clears the console window
* **`void wait()`**
    * Wait for input before continuing code
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
    * Specifically change the active text color
* **`void setBackgroundColor(const Color color = Color::BLACK)`**
    * Specifically change the active background color

### Input
* **`int in(std::string& input)`**
    * Fill the parameter `string` with input from the promt
    * Includes whitespace
    * Minimal error handeling
        * returned 0 means a successful operation
        * returned -1 means EOF error
        * returned -2 means other kind of failure
* **`int in(char& input)`**
    * Fill the parameter `char` with input from the promt
    * Takes first input and no enter is needed
    * Does not have any error handling
* **`int in(int& input)`**
    * Fill the parameter `int` with input from the promt
    * Purge anyting after the first (if any) none-number symbol
    * Minimal error handling
        * returned 0 means a successful operation
        * returned -1 means error: not a number
* **`int in(float& input)`**
    * Fill the parameter `float` with input from the promt
    * Purge anyting after the first (if any) none-number symbol
    * Minimal error handling
        * returned 0 means a successful operation
        * returned -1 means error: not a number
* **`int in(double& input)`**
    * Fill the parameter `double` with input from the promt
    * Purge anyting after the first (if any) none-number symbol
    * Minimal error handling
        * returned 0 means a successful operation
        * returned -1 means error: not a number

# Development
## File.hpp
* A library that make it easy to interface with files
* Using `fio` namespace, stands for "file In/Out"
* **Currently Untested**
### Data structures
* **`struct File`**
    * Conaints:
        * `std::string` path
        * `std::vector<std::string>` content
    * Custom `operator` functions
        * `std::string& operator[](const unsigned int index)`
            * Access `fio::File.content[]` at index
        * `bool operator==(const File& other)`
            * Check if `fio::File.path` and `fio::File.content` are the same
        * `bool operator!=(const File& other)`
            * Check if `fio::File.path` or `fio::File.content` are the arn't same
        * `File& operator=(const File& other)`
            * Set content to be the same
            * Doesn't change file path
        * `File& operator+(const std::string& line)`
            * Adds string to the end of `fio::File.content`
            * Doesn't change file path
        * `File& operator+=(const File& other)`
            * Adds the rightside `fio::File.content` at the end of leftsides `fio::File.content` 
            * Doesn't change file path
### Check
* **`bool exist(const std::string& path)`**
    * Checks if file at path is available
### In
* **`bool load(File& file)`**
    * Read from the file at `fio::File.path` to `fio::File.contnet`
* **`bool load(File& file, const std::string& path)`**
    * Same as above but with custom path
    * Will uptade the files path
* **`bool load(std::vector<std::string>& content, const std::string& path)`**
    * Variant that doesn't use the custom data structure `fio::File`
### Out
* **`bool write(std::string output, const std::string path, bool append = true)`**
    * Writes a `string` to a file at path
    * If append is set to `false` the file at path will be cleared
* **`bool save(File& file)`**
    * Will clear and write to file at `fio::File.path` form `fio::File.contnet`
* **`bool save(File& file, const std::string& path, bool updatePath = false)`**
    * Same as above function but with costom path
    * May uptade `fio::File.path` to the new path if updatePath is set to `true`
* **`bool save(std::vector<std::string>& content, const std::string& path)`**
    * Variant that doesn't use the custom data structure `fio::File`

# Known Issues
* File.hpp is untested

# Planned
* Logger using file & wci
    * Write in console and to files
        * log file, error file, & critical file
    * Inspiered by Unity3D's `Debug.Log("Mesage");`

# Notes
* Implementation will be moved to the header once it's in a usable state

# Style Guide
## Library Name
*Abbreviation explanation*
* General information
* Such as namespace
### Structural divitions
* **`Function`**
    * Function explanation
* **`Function`**
    * Function explanation