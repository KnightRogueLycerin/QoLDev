#ifndef KLOG_HPP
#define KLOG_HPP

//============================================================================
// Name        : KnightRogueLycerin's Logger
// Author      : KnightRougeLycerin
// Version     : 1.0
// Copyright   : GNU GPLv3
// Description : Logging functions
//============================================================================

#include <ctime>

#include "WCI.hpp"
#include "FIO.hpp"

namespace klog {
    /* Hard settings */
    namespace dir{
        const static std::string DIRECTORY = "Logs";
        const static std::string CRITICAL = DIRECTORY + "\\Criticals.log";
        const static std::string WARNING = DIRECTORY + "\\Warnings.log";
        const static std::string LOG = DIRECTORY + "\\Logs.log";
    }
    /* Time stamper */
    void timeStamp(std::string& stamp){
        time_t now = time(0);
        char timestamp[12] = "";
        strftime (timestamp, 12,"[%H:%M:%S] ", localtime(&now));
        stamp = timestamp;
    };
    /* Log function */
    bool critical(const std::string& message, bool inConsole = false){
        std::string t; timeStamp(t);
        if(fio::write(t + message, dir::CRITICAL)){
            if(inConsole){
                wci::out(message, wci::RED);
            }
             return true;   
        }
        wci::out("Faild to log Critical: " + message, wci::RED);
        return false;
    };
    bool warning(const std::string& message, bool inConsole = false){
        std::string t; timeStamp(t);
        if(fio::write(t + message, dir::WARNING)){
            if(inConsole){
                wci::out(message, wci::YELLOW);
            }
             return true;
        }
        wci::out("Faild to log Warrning: " + message, wci::RED);
        return false;
    };
    bool log(const std::string& message, bool inConsole = false){
        std::string t; timeStamp(t);
        if(fio::write(t + message, dir::LOG)){
            if(inConsole){
                wci::out(message, wci::GRAY);
            }
             return true;   
        }
        wci::out("Faild to log: " + message, wci::RED);
        return false;
    };
    /* Misc */
    bool reset(){
        return fio::clear(dir::LOG) && fio::clear(dir::WARNING) && fio::clear(dir::CRITICAL);
    };
    bool create(){
        // Create directory
        fio::makeDirectory(dir::DIRECTORY);
        // Create file
        return reset();
    }
};

#endif  // KLOG_HPP