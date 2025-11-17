// DisplayManager.h
#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <string>
#include <vector>

class User;
class NewsManager;

class DisplayManager {
public:
    static void displayWelcome();
    static void displayLoginMenu();
    static void displayMainMenu();
    static void displaySentimentOptions();
    static void displayNewsOptions();
    static void displayGoodbye();
    
    static int getValidatedInput(const std::string& prompt, int min, int max);
    static std::string getStringInput(const std::string& prompt);
    
    static void runNewsInterface(User* user, NewsManager* newsManager);
};

#endif