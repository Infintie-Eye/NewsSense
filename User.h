// User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string username;
    std::string password;
    std::vector<std::string> preferences; // Stores user's news preferences
    std::string sentimentPreference; // positive, negative, or neutral

public:
    User(const std::string& uname, const std::string& pwd);
    
    // Getters
    std::string getUsername() const;
    std::string getSentimentPreference() const;
    
    // Setters
    void setSentimentPreference(const std::string& sentiment);
    void addPreference(const std::string& category);
    
    // Utility
    bool hasPreference(const std::string& category) const;
    void displayPreferences() const;
};

#endif