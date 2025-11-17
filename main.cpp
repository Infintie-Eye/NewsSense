#include <iostream>
#include "User.h"
#include "NewsManager.h"
#include "SentimentAnalyzer.h"
#include "DisplayManager.h"
#include "FileHandler.h"

int main() {
    DisplayManager::displayWelcome();
    
    // Initialize news manager and load news data
    NewsManager newsManager;
    newsManager.loadNewsFromFile("finance", "news_data/finance.txt");
    newsManager.loadNewsFromFile("sports", "news_data/sports.txt");
    newsManager.loadNewsFromFile("geopolitics", "news_data/geopolitics.txt");
    newsManager.loadNewsFromFile("space_science", "news_data/space_science.txt");
    newsManager.loadNewsFromFile("technology", "news_data/technology.txt");
    newsManager.loadNewsFromFile("health", "news_data/health.txt");
    newsManager.loadNewsFromFile("entertainment", "news_data/entertainment.txt");
    
    // Main application loop
    bool running = true;
    User* currentUser = nullptr;
    
    while (running) {
        if (currentUser == nullptr) {
            // User not logged in, show login menu
            DisplayManager::displayLoginMenu();
            int choice = DisplayManager::getValidatedInput("Enter your choice (1-3): ", 1, 3);
            
            switch (choice) {
                case 1: { // Login
                    std::string username = DisplayManager::getStringInput("Enter username: ");
                    std::string password = DisplayManager::getStringInput("Enter password: ");
                    
                    if (FileHandler::validateUser(username, password)) {
                        currentUser = FileHandler::loadUser(username);
                        std::cout << "Login successful! Welcome, " << username << "!" << std::endl;
                    } else {
                        std::cout << "Invalid username or password. Please try again." << std::endl;
                    }
                    break;
                }
                case 2: { // Register
                    std::string username = DisplayManager::getStringInput("Enter a new username: ");
                    
                    if (FileHandler::userExists(username)) {
                        std::cout << "Username already exists. Please choose another." << std::endl;
                    } else {
                        std::string password = DisplayManager::getStringInput("Enter a password: ");
                        User newUser(username, password);
                        
                        if (FileHandler::saveUser(newUser)) {
                            std::cout << "Registration successful! You can now login." << std::endl;
                        } else {
                            std::cout << "Registration failed. Please try again." << std::endl;
                        }
                    }
                    break;
                }
                case 3: { // Exit
                    running = false;
                    break;
                }
            }
        } else {
            // User is logged in, show main menu
            DisplayManager::displayMainMenu();
            int choice = DisplayManager::getValidatedInput("Enter your choice (1-4): ", 1, 4);
            
            switch (choice) {
                case 1: { // View News
                    DisplayManager::runNewsInterface(currentUser, &newsManager);
                    break;
                }
                case 2: { // Update Preferences
                    DisplayManager::displaySentimentOptions();
                    int sentimentChoice = DisplayManager::getValidatedInput("Select sentiment preference (1-3): ", 1, 3);
                    
                    std::string sentiment;
                    switch (sentimentChoice) {
                        case 1: sentiment = "positive"; break;
                        case 2: sentiment = "negative"; break;
                        case 3: sentiment = "neutral"; break;
                    }
                    
                    currentUser->setSentimentPreference(sentiment);
                    std::cout << "Sentiment preference updated to " << sentiment << std::endl;
                    break;
                }
                case 3: { // View Profile
                    currentUser->displayPreferences();
                    break;
                }
                case 4: { // Logout
                    delete currentUser;
                    currentUser = nullptr;
                    std::cout << "You have been logged out." << std::endl;
                    break;
                }
            }
        }
    }
    
    DisplayManager::displayGoodbye();
    
    // Clean up
    if (currentUser != nullptr) {
        delete currentUser;
    }
    
    return 0;
}