//============================================================================
// Name        : My Quality of Life Development
// Author      : KnightRougeLycerin
// Version     : 0.02
// Copyright   : GNU GPLv3
// Description : Libraries for QoL
//============================================================================

#include "WCI.hpp"
#include "FIO.hpp"

void wait_next(bool end = false){
    if(!end)
        wci::out("\nPress any key to coninue testing...", wci::DARK_GRAY);
    else
        wci::out("\nPress any key to complete testing...", wci::DARK_GRAY);
    wci::wait();
    wci::clear();
}

int wci_test(){
    // Datablock
    char c;
    int err, integer;
    float floating;
    double real;
    std::string s;
    /* Testing */
    if(true){  // Color, out, & wait test 
        wci::out("\tCOLOR, WCI::OUT, & WAIT TEST\n", wci::DARK_TEAL);

        wci::setTextColor(wci::TEAL);
        wci::out("Hello ", false);
        wci::out("World", wci::GREEN, false);
        wci::out("!");
        wci::out("////////////", wci::BLACK, wci::YELLOW);
        
        wci::setColorDefault();

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
    if(true){ // In std::string test
        wci::out("\tIN(STRING) TEST\n", wci::DARK_TEAL);

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
}

void write(const fio::File& f, bool append = true){
    fio::write("This is an added line of text", f.path, append);
}
void check(const fio::File& f){
    wci::out(f.path + " ", false);
    if(fio::exist(f.path))
        wci::out("exist", wci::GREEN);
    else
        wci::out("is missing", wci::RED);
}
void line(const fio::File& f, std::size_t index){
    wci::out(f.path + "[" + std::to_string(index) + "]: ", false);
    out(f[index], wci::GRAY);
}
void print(const fio::File& f){
    wci::out("File: " + f.path);
    if(!f.content.empty())
        for(auto line : f.content){
            out("\t" + line, wci::GRAY);
        }
    else
        out("\tThis file is empty", wci::DARK_RED);
}
int fio_test(){ // Asume wci.hpp works for consol IO
    wci::out("Creating local files", wci::TEAL);
    
    fio::File Feoh("_Feoh.test");    // First symbol of the Futhrak
    fio::File Ur("_Ur.test");        // Second symbol of the Futhrak
    fio::File Thorn("_Thorn.test");  // Third symbol of the Futhrak
    
    wci::out("Filling local files with content", wci::TEAL);
    Feoh.content.push_back("This is test file Feoh");
    Feoh.content.push_back("This is the second row");
    
    Ur.content.push_back("This is test file Ur");
    Ur.content.push_back("This is the second row");
    Ur.content.push_back("This is the third row");
    
    Thorn.content.push_back("This is test file Thorn");
    Thorn.content.push_back("This is the second row");
    Thorn.content.push_back("This is the third row");
    Thorn.content.push_back("This is the fourth row");

    wci::out("Printing local content", wci::TEAL);
    print(Feoh); print(Ur); print(Thorn);

    wci::out("Save local files", wci::TEAL);
    fio::save(Feoh); fio::save(Ur); fio::save(Thorn);

    wci::out("Clear local files", wci::TEAL);
    Feoh.content.clear(); Ur.content.clear(); Thorn.content.clear();
    print(Feoh); print(Ur); print(Thorn);

    wci::out("Write directly to saved files", wci::TEAL);
    write(Feoh); write(Ur); write(Thorn, false);

    wci::out("Check if saved files exsist", wci::TEAL);
    check(Feoh); check(Ur); check(Thorn);

    wci::out("Load saved files", wci::TEAL);
    fio::load(Feoh); fio::load(Ur); fio::load(Thorn);

    wci::out("Printing local content", wci::TEAL);
    print(Feoh); print(Ur); print(Thorn);

    wci::out("Printing spesific content lines", wci::TEAL);
    line(Feoh, 1); line(Ur, 2); line(Thorn, 0);

    wait_next();
    return 0;
}

int main() {
    int err;
    // wci testing
    if(0){   
        err = wci_test();
        if(err != 0)
            wci::out("WCI Error code:" + std::to_string(err), wci::RED);
    }
    // fio testing
    if(1){
        err = fio_test();
        if(err != 0)
            wci::out("FIO Error code:" + std::to_string(err), wci::RED);
    }
    
    wci::out("Thank you for participating!", wci::PINK);
    wait_next(true);
    return 0;
}