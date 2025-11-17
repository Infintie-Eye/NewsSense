// SentimentAnalyzer.cpp
#include "SentimentAnalyzer.h"
#include <sstream>
#include <algorithm>
#include <iostream>

SentimentAnalyzer::SentimentAnalyzer() {
    initializeWordLists();
}

void SentimentAnalyzer::initializeWordLists() {
    // Positive words
    positiveWords["good"] = 1;
    positiveWords["great"] = 2;
    positiveWords["excellent"] = 3;
    positiveWords["positive"] = 2;
    positiveWords["success"] = 2;
    positiveWords["growth"] = 1;
    positiveWords["happy"] = 2;
    positiveWords["win"] = 2;
    positiveWords["advance"] = 1;
    positiveWords["benefit"] = 1;
    
    // Negative words
    negativeWords["bad"] = 1;
    negativeWords["terrible"] = 3;
    negativeWords["negative"] = 2;
    negativeWords["fail"] = 2;
    negativeWords["loss"] = 2;
    negativeWords["crisis"] = 3;
    negativeWords["disaster"] = 3;
    negativeWords["decline"] = 2;
    negativeWords["problem"] = 1;
    negativeWords["risk"] = 1;
}

std::string SentimentAnalyzer::analyzeSentiment(const std::string& text) {
    int score = getSentimentScore(text);
    
    if (score > 2) return "positive";
    if (score < -2) return "negative";
    return "neutral";
}

int SentimentAnalyzer::getSentimentScore(const std::string& text) {
    std::stringstream ss(text);
    std::string word;
    int score = 0;
    
    while (ss >> word) {
        // Convert to lowercase
        std::transform(word.begin(), word.end(), word.begin(), 
                      [](unsigned char c){ return std::tolower(c); });
        
        // Remove punctuation
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        
        // Check positive words
        if (positiveWords.find(word) != positiveWords.end()) {
            score += positiveWords[word];
        }
        
        // Check negative words
        if (negativeWords.find(word) != negativeWords.end()) {
            score -= negativeWords[word];
        }
    }
    
    return score;
}

void SentimentAnalyzer::displaySentimentStats(const std::string& category, const std::vector<std::string>& sentiments) {
    int positive = 0, negative = 0, neutral = 0;
    
    for (const auto& sentiment : sentiments) {
        if (sentiment == "positive") positive++;
        else if (sentiment == "negative") negative++;
        else neutral++;
    }
    
    std::cout << "Sentiment Statistics for " << category << ":" << std::endl;
    std::cout << "Positive: " << positive << " (" << (positive * 100.0 / sentiments.size()) << "%)" << std::endl;
    std::cout << "Negative: " << negative << " (" << (negative * 100.0 / sentiments.size()) << "%)" << std::endl;
    std::cout << "Neutral: " << neutral << " (" << (neutral * 100.0 / sentiments.size()) << "%)" << std::endl;
}