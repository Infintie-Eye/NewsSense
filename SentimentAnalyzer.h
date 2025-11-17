// SentimentAnalyzer.h
#ifndef SENTIMENTANALYZER_H
#define SENTIMENTANALYZER_H

#include <string>
#include <vector>
#include <map>

class SentimentAnalyzer {
private:
    std::map<std::string, int> positiveWords;
    std::map<std::string, int> negativeWords;
    
    void initializeWordLists();

public:
    SentimentAnalyzer();
    
    std::string analyzeSentiment(const std::string& text);
    int getSentimentScore(const std::string& text);
    void displaySentimentStats(const std::string& category, const std::vector<std::string>& sentiments);
};

#endif