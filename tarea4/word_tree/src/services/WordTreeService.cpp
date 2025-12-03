#include "../../includes/services/WordTreeService.h"
#include <iostream>

void WordTreeService::insertWord(std::string word) {
    repository.insert(word);
    std::cout << "Word '" << word << "' inserted successfully.\n";
}

void WordTreeService::displayWordsAlphabetically() {
    std::vector<std::string> words = repository.getWordsAlphabetically();
    
    if (words.empty()) {
        std::cout << "No words in the tree.\n";
        return;
    }
    
    std::cout << "Words in alphabetical order:\n";
    for (size_t i = 0; i < words.size(); i++) {
        std::cout << i + 1 << ". " << words[i] << "\n";
    }
}

void WordTreeService::searchForWord(std::string word) {
    bool found = repository.search(word);
    
    if (found) {
        std::cout << "Word '" << word << "' found in the tree.\n";
    } else {
        std::cout << "Word '" << word << "' not found in the tree.\n";
    }
}

void WordTreeService::displayWordsPerLevel() {
    std::vector<int> levelCounts = repository.getWordsPerLevel();
    
    if (levelCounts.empty()) {
        std::cout << "No words in the tree.\n";
        return;
    }
    
    std::cout << "Words per level:\n";
    for (size_t i = 0; i < levelCounts.size(); i++) {
        std::cout << "Level " << i << ": " << levelCounts[i] << " word(s)\n";
    }
}

void WordTreeService::displayAllWords() {
    std::vector<std::string> words = repository.getWordsAlphabetically();
    
    std::cout << "=== ALL WORDS ===\n";
    if (words.empty()) {
        std::cout << "No words in the tree.\n";
        return;
    }
    
    std::cout << "Total words: " << words.size() << "\n";
    std::cout << "Words in alphabetical order:\n";
    for (size_t i = 0; i < words.size(); i++) {
        std::cout << i + 1 << ". " << words[i] << "\n";
    }
}

void WordTreeService::displayStatistics() {
    std::vector<std::string> words = repository.getWordsAlphabetically();
    std::vector<int> levelCounts = repository.getWordsPerLevel();
    
    std::cout << "=== TREE STATISTICS ===\n";
    std::cout << "Total words: " << words.size() << "\n";
    std::cout << "Tree height: " << levelCounts.size() - 1 << " levels\n";
    
    std::cout << "Words per level:\n";
    for (size_t i = 0; i < levelCounts.size(); i++) {
        std::cout << "  Level " << i << ": " << levelCounts[i] << " word(s)\n";
    }
}
