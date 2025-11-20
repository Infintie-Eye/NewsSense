// NewsManager.h
#ifndef NEWSMANAGER_H
#define NEWSMANAGER_H

#include <string>
#include <vector>
#include <map>


// struct NewsParagraph {
//     std::string content;
//     std::string sentiment;
// };

// struct NewsArticle {
//     std::string title;
//     std::string type;
//     std::string author;
//     std::string date;
//     std::vector<NewsParagraph> paragraphs; // Multiple paragraphs with different sentiments
//     std::string overallSentiment; // Main sentiment for filtering
// };


struct NewsArticle {
    std::string title;
    std::string type;
    std::string author;
    std::string date;
    std::string content;
    std::string sentiment; // positive, negative, neutral
};

class NewsManager {
private:
    std::map<std::string, std::vector<NewsArticle>> newsDatabase; // category -> articles
    std::vector<std::string> categories;

public:
    NewsManager();
    
    // Load news from files
    void loadNewsFromFile(const std::string& category, const std::string& filename);
    
    // Getters
    std::vector<std::string> getCategories() const;
    std::vector<NewsArticle> getNewsByCategory(const std::string& category) const;
    std::vector<NewsArticle> getNewsByCategoryAndSentiment(const std::string& category, const std::string& sentiment) const;
    
    // Display
    void displayCategories() const;
    void displayNewsTitles(const std::string& category) const;
    void displayNewsArticle(const NewsArticle& article) const;
};

#endif