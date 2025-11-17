// FileHandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include <map>

class User;

class FileHandler {
public:
    static bool userExists(const std::string& username);
    static bool validateUser(const std::string& username, const std::string& password);
    static bool saveUser(const User& user);
    static User* loadUser(const std::string& username);
    static bool initializeNewsFiles();
    static std::vector<std::string> readNewsFile(const std::string& filename);
    static bool appendToNewsFile(const std::string& filename, const std::string& content);
};

#endif