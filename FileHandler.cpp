// FileHandler.cpp
#include "FileHandler.h"
#include "User.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool FileHandler::userExists(const std::string& username) {
    std::ifstream file("users.txt");
    if (!file.is_open()) return false;
    
    std::string line;
    while (getline(file, line)) {
        if (line.find("USERNAME:" + username) == 0) {
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

bool FileHandler::validateUser(const std::string& username, const std::string& password) {
    std::ifstream file("users.txt");
    if (!file.is_open()) return false;
    
    std::string line;
    bool foundUser = false;
    bool correctPassword = false;
    
    while (getline(file, line)) {
        if (line.find("USERNAME:" + username) == 0) {
            foundUser = true;
        } else if (foundUser && line.find("PASSWORD:" + password) == 0) {
            correctPassword = true;
            break;
        }
    }
    
    file.close();
    return foundUser && correctPassword;
}

bool FileHandler::saveUser(const User& user) {
    std::ofstream file("users.txt", std::ios::app);
    if (!file.is_open()) return false;
    
    file << "USERNAME:" << user.getUsername() << std::endl;
    // In a real implementation, you would hash the password
    file << "PASSWORD:" << "password_hash" << std::endl; // Placeholder
    file << "SENTIMENT:" << user.getSentimentPreference() << std::endl;
    file << "----------------------------------------" << std::endl;
    
    file.close();
    return true;
}

User* FileHandler::loadUser(const std::string& username) {
    std::ifstream file("users.txt");
    if (!file.is_open()) return nullptr;
    
    std::string line;
    bool foundUser = false;
    std::string password, sentiment;
    
    while (getline(file, line)) {
        if (line.find("USERNAME:" + username) == 0) {
            foundUser = true;
        } else if (foundUser && line.find("PASSWORD:") == 0) {
            password = line.substr(9);
        } else if (foundUser && line.find("SENTIMENT:") == 0) {
            sentiment = line.substr(10);
            break;
        }
    }
    
    file.close();
    
    if (foundUser) {
        return new User(username, password);
    }
    
    return nullptr;
}

bool FileHandler::initializeNewsFiles() {
    // This would create initial news files if they don't exist
    // For the purpose of this example, we'll assume they're already created
    return true;
}

std::vector<std::string> FileHandler::readNewsFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    
    return lines;
}

bool FileHandler::appendToNewsFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) return false;
    
    file << content << std::endl;
    file.close();
    return true;
}