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
        // Operators
        File& operator=(const File& other){
            content.clear();
            for(auto line : other.content)
                content.push_back(line);
            return *this;
        }
    };
    // Implementation ment to left alone >:(
    namespace implement{

    }
    /* Misc */
    bool exist(const std::string& path);
    /* In */
    bool load(std::vector<std::string>& content, const std::string& path);
    bool load(File& file, const std::string& path);
    bool load(File& file);
    /* Out */
    bool write(std::string output, const std::string path, bool append = true);

    bool save(std::vector<std::string>& content, const std::string& path);
    bool save(File& file, const std::string& path, bool updatePath = false);
    bool save(File& file);
}

#endif