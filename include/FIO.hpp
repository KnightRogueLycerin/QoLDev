#ifndef FIO_HPP
#define FIO_HPP

//============================================================================
// Name        : File In/Out
// Author      : KnightRougeLycerin
// Version     : 0.01
// Copyright   : GNU GPLv3
// Description : User friendly file I/O
//============================================================================

#include <string>
#include <vector>
#include <fstream>

namespace fio {
    // Data structure
    struct File{
        std::string path;
        std::vector<std::string> content;
        // Constructor
        File(std::string s):path(s){}
        // Operators
        std::string& operator[](std::size_t index){
            return content[index];
        }
        const std::string& operator[](std::size_t index) const{
            return content[index];
        }
        bool operator==(const File& other){
            return path == other.path && content == other.content;
        }
        bool operator!=(const File& other){
            return path != other.path || content != other.content;
        }
        File& operator=(const File& other){
            content.clear();
            for(auto line : other.content)
                content.push_back(line);
            return *this;
        }
        File& operator+(const std::string& line){
            content.push_back(line);
        }
        File& operator+=(const File& other){
            for(auto line : other.content)
                content.push_back(line);
            return *this;
        }
    };
    /* Misc */
    bool exist(const std::string& path);
    /* In */
    bool load(std::vector<std::string>& content, const std::string& path);
    bool load(File& file, const std::string& path);
    bool load(File& file);
    /* Out */
    bool write(const std::string& output, const std::string& path, bool append = true);

    bool save(std::vector<std::string>& content, const std::string& path);
    bool save(File& file, const std::string& path, bool updatePath = false);
    bool save(File& file);
}

#endif