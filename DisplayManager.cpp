// DisplayManager.cpp
#include "DisplayManager.h"
#include "User.h"
#include "NewsManager.h"
#include <iostream>
#include <limits>

void DisplayManager::displayWelcome() {
    std::cout << "========================================" << std::endl;
    std::cout << "         WELCOME TO Quick Bits          " << std::endl;
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
    std::cout << "\nMAIN MENU: \n" << std::endl;
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
    std::cout << "\nThank you for using 'Quick Bits' Personalized News Aggregator!" << std::endl;
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

// void DisplayManager::runNewsInterface(User* user, NewsManager* newsManager) {
//     bool inNewsInterface = true;
    
//     while (inNewsInterface) {
//         // Display categories
//         newsManager->displayCategories();
//         int categoryChoice = getValidatedInput("Select a category (1-7): ", 1, 7);
        
//         auto categories = newsManager->getCategories();
//         std::string selectedCategory = categories[categoryChoice - 1];
        
//         // Get sentiment preference FIRST
//         displaySentimentOptions();
//         int sentimentChoice = getValidatedInput("Select sentiment preference (1-4): ", 1, 4);
        
//         std::string sentiment;
//         switch (sentimentChoice) {
//             case 1: sentiment = "positive"; break;
//             case 2: sentiment = "negative"; break;
//             case 3: sentiment = "neutral"; break;
//             case 4: sentiment = "all"; break;
//         }
        
//         // Get filtered articles based on sentiment
//         std::vector<NewsArticle> filteredArticles;
        
//         if (sentiment == "all") {
//             filteredArticles = newsManager->getNewsByCategory(selectedCategory);
//         } else {
//             filteredArticles = newsManager->getNewsByCategoryAndSentiment(selectedCategory, sentiment);
//         }
        
//         // Check if we have any articles after filtering
//         if (filteredArticles.empty()) {
//             std::cout << "No articles found with the selected sentiment: " << sentiment << std::endl;
//             std::cout << "Please try a different sentiment or category.\n" << std::endl;
            
//             // News options after no articles found
//             displayNewsOptions();
//             int newsOption = getValidatedInput("Select an option (1-3): ", 1, 3);
            
//             switch (newsOption) {
//                 case 1: // Read another article - continue loop
//                 case 2: // Change category - continue loop
//                     break;
//                 case 3: // Return to Main Menu
//                     inNewsInterface = false;
//                     break;
//             }
//             continue;
//         }
        
//         // Display filtered articles with their overall sentiment
//         std::cout << "\nAvailable Articles in " << selectedCategory << " [" << sentiment << " sentiment]:" << std::endl;
//         for (size_t i = 0; i < filteredArticles.size() && i < 5; ++i) {
//             std::cout << i+1 << ". " << filteredArticles[i].title 
//                       << " [Overall: " << filteredArticles[i].overallSentiment << "]" << std::endl;
//         }
        
//         int maxArticles = filteredArticles.size();
//         int articleChoice = getValidatedInput("Select an article (1-" + std::to_string(maxArticles) + "): ", 1, maxArticles);
        
//         // Display the selected article (will now show paragraph-level sentiments)
//         if (articleChoice <= filteredArticles.size()) {
//             newsManager->displayNewsArticle(filteredArticles[articleChoice - 1]);
            
//             // Additional information about the article's sentiment composition
//             auto& article = filteredArticles[articleChoice - 1];
//             std::cout << "\nArticle contains " << article.paragraphs.size() << " paragraphs with varying sentiments." << std::endl;
//         }
        
//         // News options
//         displayNewsOptions();
//         int newsOption = getValidatedInput("Select an option (1-3): ", 1, 3);
        
//         switch (newsOption) {
//             case 1: // Read another article - continue loop
//                 break;
//             case 2: // Change category - continue loop
//                 break;
//             case 3: // Return to Main Menu
//                 inNewsInterface = false;
//                 break;
//         }
//     }
// }









void DisplayManager::runNewsInterface(User* user, NewsManager* newsManager) {
    bool inNewsInterface = true;
    
    while (inNewsInterface) {
        // Display categories
        newsManager->displayCategories();
        int categoryChoice = getValidatedInput("Select a category (1-7): ", 1, 7);
        
        auto categories = newsManager->getCategories();
        std::string selectedCategory = categories[categoryChoice - 1];
        
        // redirecting to category
        jumpCategory:

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
        




        // Get articles based on sentiment filter
        std::vector<NewsArticle> filteredArticles;
        auto allArticles = newsManager->getNewsByCategory(selectedCategory);
        
        if (sentiment == "all") {
            filteredArticles = allArticles;
        } else {
            for (const auto& article : allArticles) {
                if (article.sentiment == sentiment) {
                    filteredArticles.push_back(article);
                }
            }
        }
        // Check if we have any articles after filtering
        if (filteredArticles.empty()) {
            std::cout << "No articles found with the selected sentiment: " << sentiment << std::endl;
            
            // News options after no articles found
            displayNewsOptions();
            int newsOption = getValidatedInput("Select an option (1-3): ", 1, 3);
            
            switch (newsOption) {
                case 1: // Read another article - continue loop
                    goto jumpCategory;
                case 2: // Change category - continue loop
                    break;
                case 3: // Return to Main Menu
                    inNewsInterface = false;
                    break;
            }
            continue;
        }
        
        // Display filtered articles
        std::cout << "Available Articles in " << selectedCategory << " [" << sentiment << " sentiment]:" << std::endl;
        for (size_t i = 0; i < filteredArticles.size() && i < 5; ++i) {
            std::cout << i+1 << ". " << filteredArticles[i].title << " [" << filteredArticles[i].sentiment << "]" << std::endl;
        }
        
        // Display the selected article
        if (articleChoice <= filteredArticles.size()) {
            newsManager->displayNewsArticle(filteredArticles[articleChoice - 1]);
        }
        
        // News options
        displayNewsOptions();
        int newsOption = getValidatedInput("Select an option (1-3): ", 1, 3);
        
        switch (newsOption) {
            case 1: // Read another article - continue loop
                goto jumpCategory;
            case 2: // Change category - continue loop
                break;
            case 3: // Return to Main Menu
                inNewsInterface = false;
                break;
        }



        // // Display the selected article
        // auto articles = newsManager->getNewsByCategory(selectedCategory);
        // if (articleChoice <= articles.size()) {
        //     if (sentiment == "all" || articles[articleChoice - 1].sentiment == sentiment) {
        //         newsManager->displayNewsArticle(articles[articleChoice - 1]);
        //     } else {
        //         std::cout << "No article with the selected sentiment found." << std::endl;
        //     }
        // }
        
        // // News options
        // displayNewsOptions();
        // int newsOption = getValidatedInput("Select an option (1-3): ", 1, 3);
        
        // switch (newsOption) {
        //     case 1: // Read another article - continue loop
        //         break;
        //     case 2: // Change category - continue loop
        //         break;
        //     case 3: // Return to Main Menu
        //         inNewsInterface = false;
        //         break;
        // }
    }
}