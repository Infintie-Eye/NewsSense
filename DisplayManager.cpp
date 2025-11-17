// DisplayManager.cpp
#include "DisplayManager.h"
#include "User.h"
#include "NewsManager.h"
#include <iostream>
#include <limits>

void DisplayManager::displayWelcome() {
    std::cout << "========================================" << std::endl;
    std::cout << "  PERSONALIZED NEWS AGGREGATOR SYSTEM  " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
}

void DisplayManager::displayLoginMenu() {
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

void DisplayManager::displayMainMenu() {
    std::cout << "\nMAIN MENU:" << std::endl;
    std::cout << "1. View News" << std::endl;
    std::cout << "2. Update Preferences" << std::endl;
    std::cout << "3. View Profile" << std::endl;
    std::cout << "4. Logout" << std::endl;
}

void DisplayManager::displaySentimentOptions() {
    std::cout << "Select Sentiment Preference:" << std::endl;
    std::cout << "1. Positive" << std::endl;
    std::cout << "2. Negative" << std::endl;
    std::cout << "3. Neutral" << std::endl;
    std::cout << "4. All Sentiments" << std::endl;
}

void DisplayManager::displayNewsOptions() {
    std::cout << "\nNEWS OPTIONS:" << std::endl;
    std::cout << "1. Read another article" << std::endl;
    std::cout << "2. Change category" << std::endl;
    std::cout << "3. Return to Main Menu" << std::endl;
}

void DisplayManager::displayGoodbye() {
    std::cout << "\nThank you for using the Personalized News Aggregator!" << std::endl;
    std::cout << "Have a great day!" << std::endl;
}

int DisplayManager::getValidatedInput(const std::string& prompt, int min, int max) {
    int choice;
    while (true) {
        std::cout << prompt;
        std::cin >> choice;
        
        if (std::cin.fail() || choice < min || choice > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

std::string DisplayManager::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

void DisplayManager::runNewsInterface(User* user, NewsManager* newsManager) {
    bool inNewsInterface = true;
    
    while (inNewsInterface) {
        // Display categories
        newsManager->displayCategories();
        int categoryChoice = getValidatedInput("Select a category (1-7): ", 1, 7);
        
        auto categories = newsManager->getCategories();
        std::string selectedCategory = categories[categoryChoice - 1];
        
        // Display news titles in selected category
        newsManager->displayNewsTitles(selectedCategory);
        int articleChoice = getValidatedInput("Select an article (1-5): ", 1, 5);
        
        // Get sentiment preference
        displaySentimentOptions();
        int sentimentChoice = getValidatedInput("Select sentiment preference (1-4): ", 1, 4);
        
        std::string sentiment;
        switch (sentimentChoice) {
            case 1: sentiment = "positive"; break;
            case 2: sentiment = "negative"; break;
            case 3: sentiment = "neutral"; break;
            case 4: sentiment = "all"; break;
        }
        
        // Display the selected article
        auto articles = newsManager->getNewsByCategory(selectedCategory);
        if (articleChoice <= articles.size()) {
            if (sentiment == "all" || articles[articleChoice - 1].sentiment == sentiment) {
                newsManager->displayNewsArticle(articles[articleChoice - 1]);
            } else {
                std::cout << "No article with the selected sentiment found." << std::endl;
            }
        }
        
        // News options
        displayNewsOptions();
        int newsOption = getValidatedInput("Select an option (1-3): ", 1, 3);
        
        switch (newsOption) {
            case 1: // Read another article - continue loop
                break;
            case 2: // Change category - continue loop
                break;
            case 3: // Return to Main Menu
                inNewsInterface = false;
                break;
        }
    }
}