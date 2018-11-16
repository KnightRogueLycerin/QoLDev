#include "FIO.hpp"

namespace fio{
    /* Misc */
    bool exist(const std::string& path){
        // Test if filepath can be opend for reading
        if(FILE *f = std::fopen(path.c_str(), "r")){
            // Clean up and return
            std::fclose(f); delete f;
            return true;
        }
        else
            return false;
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
    }
    bool load(File& file, const std::string& path){
        file.path = path;
        return load(file.content, file.path);
    }
    bool load(File& file){
        return load(file.content, file.path);
    }

    /* Out */
    bool write(const std::string& output, const std::string& path, bool append){
        std::ofstream writer(path);
        if(!writer.is_open())
            return false;
        if(!append)
            writer.clear();
        writer << output << "\n";
        writer.close();
        return true;
    }

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
    }
    bool save(File& file, const std::string& path, bool updatePath){
        if(updatePath)
            file.path = path;
        return save(file.content, file.path);
    }
    bool save(File& file){
        return save(file.content, file.path);
    }
}