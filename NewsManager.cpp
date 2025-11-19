// NewsManager.cpp
#include "NewsManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

NewsManager::NewsManager() {
    // Initialize categories
    categories = {"finance", "sports", "geopolitics", "space_science", 
                  "technology", "health", "entertainment"};
}

void NewsManager::loadNewsFromFile(const std::string& category, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    NewsArticle currentArticle;
    bool readingContent = false;
    bool hasArticleData = false;
    
    while (getline(file, line)) {
        // Check for separator line (indicating end of article)
        if (line.find("----------------------------------------") == 0) {
            if (hasArticleData) {
                // Save current article
                newsDatabase[category].push_back(currentArticle);
                currentArticle = NewsArticle();
                readingContent = false;
                hasArticleData = false;
            }
            continue; // Skip separator line
        }
                // Trim whitespace from the line
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        if (line.find("TITLE:") == 0) {
            if (hasArticleData) {
                // Save previous article
                newsDatabase[category].push_back(currentArticle);
                currentArticle = NewsArticle();
                readingContent = false;
            }
            currentArticle.title = line.substr(6);
            hasArticleData = true;
        } 
        else if (line.find("TYPE:") == 0) {
            currentArticle.type = line.substr(5);
        } 
        else if (line.find("AUTHOR:") == 0) {
            currentArticle.author = line.substr(7);
        } 
        else if (line.find("DATE:") == 0) {
            currentArticle.date = line.substr(5);
        } 
        else if (line.find("SENTIMENT:") == 0) {
            currentArticle.sentiment = line.substr(10);
        } 
        else if (line.find("CONTENT:") == 0) {
            readingContent = true;
            currentArticle.content = line.substr(8);
                        // Only add newline if there's actual content after "CONTENT:"
            if (!currentArticle.content.empty()) {
                currentArticle.content += "\n";
            }
        } 
        else if (readingContent && !line.empty()) {
            currentArticle.content += line + "\n";
        }
    }
    
    // Add the last article
    if (readingContent) {
        newsDatabase[category].push_back(currentArticle);
    }
    
    file.close();
}

std::vector<std::string> NewsManager::getCategories() const {
    return categories;
}

std::vector<NewsArticle> NewsManager::getNewsByCategory(const std::string& category) const {
    auto it = newsDatabase.find(category);
    if (it != newsDatabase.end()) {
        return it->second;
    }
    return {};
}

std::vector<NewsArticle> NewsManager::getNewsByCategoryAndSentiment(const std::string& category, const std::string& sentiment) const {
    std::vector<NewsArticle> result;
    auto articles = getNewsByCategory(category);
    
    for (const auto& article : articles) {
        if (article.sentiment == sentiment) {
            result.push_back(article);
        }
    }
    
    return result;
}

void NewsManager::displayCategories() const {
    std::cout << "Available News Categories:" << std::endl;
    for (size_t i = 0; i < categories.size(); ++i) {
        std::cout << i+1 << ". " << categories[i] << std::endl;
    }
}

void NewsManager::displayNewsTitles(const std::string& category) const {
    auto articles = getNewsByCategory(category);
    std::cout << "Available Articles in " << category << ":" << std::endl;
    
    for (size_t i = 0; i < articles.size() && i < 5; ++i) {
        std::cout << i+1 << ". " << articles[i].title << " [" << articles[i].sentiment << "]" << std::endl;
    }
}

void NewsManager::displayNewsArticle(const NewsArticle& article) const {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "TITLE: " << article.title << std::endl;
    std::cout << "TYPE: " << article.type << std::endl;
    std::cout << "AUTHOR: " << article.author << std::endl;
    std::cout << "DATE: " << article.date << std::endl;
    std::cout << "SENTIMENT: " << article.sentiment << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << article.content << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}