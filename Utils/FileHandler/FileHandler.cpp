#include "FileHandler.hpp"

// Constructor: Validate file path
FileHandler::FileHandler(const std::string& path) : filePath(path) {
    if (filePath.empty()) {
        throw std::invalid_argument("File path cannot be empty.");
    }
}

// Write to file (overwrite mode)
void FileHandler::writeToFile(const std::string& data) {
	// std::lock_guard<std::mutex> lock(fileMutex);
    std::ofstream file(filePath, std::ios::out);
    if (!file) 
		throw std::runtime_error("Failed to open file for writing.");
    file << data;
}

// Append to file
void FileHandler::appendToFile(const std::string& data) {
	// std::lock_guard<std::mutex> lock(fileMutex);
    std::ofstream file(filePath, std::ios::app);
    if (!file) 
		throw std::runtime_error("Failed to open file for appending.");
    file << data;
}

// Read entire file into a string
std::string FileHandler::readFile() {
	// std::lock_guard<std::mutex> lock(fileMutex);
    std::ifstream file(filePath, std::ios::in);
    if (!file) 
		throw std::runtime_error("Failed to open file for reading.");

    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

// Read file line by line
std::vector<std::string> FileHandler::readLines() {
		// std::lock_guard<std::mutex> lock(fileMutex);
    std::ifstream file(filePath, std::ios::in);
    if (!file) 
		throw std::runtime_error("Failed to open file for reading.");

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Read binary file
std::vector<char> FileHandler::readBinary() {
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);
    if (!file) 
		throw std::runtime_error("Failed to open binary file.");

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        throw std::runtime_error("Failed to read binary file.");
    }
    return buffer;
}

// Write binary data
void FileHandler::writeBinary(const std::vector<char>& data) {
    std::ofstream file(filePath, std::ios::binary | std::ios::out);
    if (!file) 
		throw std::runtime_error("Failed to open binary file for writing.");
    file.write(data.data(), data.size());
}

// Check if file exists
bool FileHandler::exists() const {
    return std::filesystem::exists(filePath);
}

// Get file size
std::size_t FileHandler::fileSize() const {
    if (!exists()) 
		return 0;
    return std::filesystem::file_size(filePath);
}
