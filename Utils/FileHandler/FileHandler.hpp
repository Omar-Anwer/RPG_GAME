#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <stdexcept>
// #include <mutex>

class FileHandler {
private:
    std::filesystem::path filePath;
	// mutable std::mutex fileMutex;

public:
    // Constructor
    explicit FileHandler(const std::string& path);

    // Write data to file (overwrite mode)
    void writeToFile(const std::string& data);

    // Append data to file
    void appendToFile(const std::string& data);

    // Read entire file contents
    std::string readFile();

    // Read file line by line
    std::vector<std::string> readLines();

    // Read binary data
    std::vector<char> readBinary();

    // Write binary data
    void writeBinary(const std::vector<char>& data);

    // Check if file exists
    bool exists() const;

    // Get file size
    std::size_t fileSize() const;
};

#endif // FILE_HANDLER_HPP
