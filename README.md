# Personalized News Aggregator with Sentiment Analysis

A C++-based command-line news aggregation system that delivers personalized news content based on user preferences and sentiment analysis.

## Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [File Formats](#file-formats)
- [Team Contributions](#team-contributions)
- [Technologies Used](#technologies-used)
- [Future Enhancements](#future-enhancements)

## Features
1. **User Authentication**: Login and registration system with persistent user data
2. **Personalized News Delivery**: News content tailored to user preferences
3. **Sentiment Analysis**: Categorizes news as positive, negative, or neutral
4. **Multi-category News**: Supports 7 news categories (Finance, Sports, Geopolitics, Space Science, Technology, Health, Entertainment)
5. **Command Line Interface**: Simple, intuitive text-based interface
6. **Data Persistence**: User profiles and news articles stored in text files
7. **Sentiment Filtering**: Users can filter news by sentiment preference

## Project Structure
NewsAggregator/
├── main.cpp # Main program entry point
├── User.h # User management header
├── User.cpp # User management implementation
├── NewsManager.h # News management header
├── NewsManager.cpp # News management implementation
├── SentimentAnalyzer.h # Sentiment analysis header
├── SentimentAnalyzer.cpp # Sentiment analysis implementation
├── DisplayManager.h # UI management header
├── DisplayManager.cpp # UI management implementation
├── FileHandler.h # File operations header
├── FileHandler.cpp # File operations implementation
├── users.txt # User database
└── news_data/ # News articles directory
├── finance.txt
├── sports.txt
├── geopolitics.txt
├── space_science.txt
├── technology.txt
├── health.txt
└── entertainment.txt


## Requirements
- C++11 compatible compiler (GCC, Clang, MSVC)
- No third-party libraries or frameworks required
- Command-line terminal

## Installation
1. Clone or download the project files
2. Ensure all files are in the same directory structure as shown above
3. Create the `news_data` directory and populate it with news articles

## Compilation
```bash
g++ -std=c++11 -o NewsAggregator main.cpp User.cpp NewsManager.cpp SentimentAnalyzer.cpp DisplayManager.cpp FileHandler.cpp 
```

## Usage
1. Run the executable:
```bash
./NewsAggregator
```
2. Follow the on-screen instructions:
- Login with existing credentials or register a new account
- Select news categories from the main menu
- Choose sentiment preference (positive, negative, or neutral)
- Browse and read news articles
- Update preferences or logout when finished

## Team Contributions
This project was developed by a team of 5 members, each responsible for distinct components:

1. User Management System (User class)
- User registration and authentication
- Preference storage and retrieval
2. News Management System (NewsManager class)
- News categorization and storage
- Article retrieval and display
3. Sentiment Analysis Engine (SentimentAnalyzer class)
- Sentiment classification algorithm
- Statistical analysis of news sentiment
4. Command Line Interface (DisplayManager class)
- User interaction flows
- Menu navigation and input validation
5. File Operations Handler (FileHandler class)
- Persistent data storage
- File I/O operations

## Technologies Used
- Programming Language: C++ (C++11 standard)
- Data Structures: Maps, Vectors, Structs
- File Handling: Standard C++ file streams
- Algorithms: String processing, sentiment scoring
- Design Patterns: Modular class-based architecture