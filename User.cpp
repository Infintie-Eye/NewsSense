// User.cpp
#include "User.h"
#include <iostream>

User::User(const std::string& uname, const std::string& pwd) 
    : username(uname), password(pwd), sentimentPreference("neutral") {}

std::string User::getUsername() const { return username; }
std::string User::getSentimentPreference() const { return sentimentPreference; }
std::string User::getPassword() const { return password; }

void User::setSentimentPreference(const std::string& sentiment) {
    sentimentPreference = sentiment;
}

void User::addPreference(const std::string& category) {
    if (!hasPreference(category)) {
        preferences.push_back(category);
    }
}

bool User::hasPreference(const std::string& category) const {
    for (const auto& pref : preferences) {
        if (pref == category) return true;
    }
    return false;
}

void User::displayPreferences() const {
    std::cout << "User: " << username << std::endl;
    std::cout << "Sentiment Preference: " << sentimentPreference << std::endl;
    std::cout << "News Categories: ";
    for (const auto& pref : preferences) {
        std::cout << pref << " ";
    }
    std::cout << std::endl;
}