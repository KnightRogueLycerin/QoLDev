#ifndef FIO_HPP
#define FIO_HPP

//============================================================================
// Name        : File In/Out
// Author      : KnightRougeLycerin
// Version     : 1.0
// Copyright   : GNU GPLv3
// Description : User friendly file I/O
//============================================================================

#include <string>
#include <vector>
#include <fstream>
#include <direct.h>

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
    bool exist(const std::string& path){
        // Test if filepath can be opend for reading
        if(FILE *f = std::fopen(path.c_str(), "r")){
            // Clean up and return
            std::fclose(f);
            return true;
        }
        else
            return false;
    };
    void makeDirectory(const std::string& path){
        mkdir(path.c_str());  // TODO: Err
    }
    /* In */
    bool load(std::vector<std::string>& content, const std::string& path){
        // Set up & sanity
        std::ifstream reader(path);
        if(!reader.is_open() || !reader.good())
            return false;
        std::string line;
        content.clear();
        // Load data
        while(!reader.eof()){
            std::getline(reader, line);
            content.push_back(line);
            line.clear();
        }
        // Clean up & return
        reader.close();
        return true;
    };
    bool load(File& file, const std::string& path){
        file.path = path;
        return load(file.content, file.path);
    };
    bool load(File& file){
        return load(file.content, file.path);
    };
    /* Out */
    bool clear(const std::string& path){
        std::ofstream writer;
        writer.open(path.c_str());
        if(!writer.is_open())
            return false;
        writer.close();
        return true;
    };
    bool write(const std::string& output, const std::string& path, bool append = true){
        std::ofstream writer;
        if(!append){
            writer.open(path.c_str());
        }
        else{
            writer.open(path.c_str(), std::ios::app);
        }
        if(!writer.is_open())
            return false;
        writer << output << "\n";
        writer.close();
        return true;
    };

    bool save(std::vector<std::string>& content, const std::string& path){
        std::ofstream writer(path);
        if(!writer.is_open())
            return false;
        writer.clear();
        for(auto& line : content){
            if(&line == &content.back())
                writer << line; // Avoid newline padding
            else
                writer << line << "\n";
        }
        writer.close();
        return true;
    };
    bool save(File& file, const std::string& path, bool updatePath = false){
        if(updatePath)
            file.path = path;
        return save(file.content, file.path);
    };
    bool save(File& file){
        return save(file.content, file.path);
    };
}

#endif  // FIO_HPP