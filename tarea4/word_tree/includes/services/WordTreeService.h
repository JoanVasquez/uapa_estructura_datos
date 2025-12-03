#ifndef WORDTREESERVICE_H
#define WORDTREESERVICE_H

#include "../repositories/WordTreeRepository.h"
#include <string>
#include <vector>

class WordTreeService {
private:
    WordTreeRepository repository;

public:
    void insertWord(std::string word);
    void displayWordsAlphabetically();
    void searchForWord(std::string word);
    void displayWordsPerLevel();
    void displayAllWords();
    void displayStatistics();
};

#endif
