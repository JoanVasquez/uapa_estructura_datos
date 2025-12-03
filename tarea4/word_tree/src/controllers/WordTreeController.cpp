#include "../../includes/controllers/WordTreeController.h"
#include <iostream>

void WordTreeController::executeOption(int option) {
    std::string word;
    
    switch (option) {
        case 1:
            std::cout << "Enter word to insert: ";
            std::getline(std::cin, word);
            service.insertWord(word);
            break;
        case 2:
            service.displayWordsAlphabetically();
            break;
        case 3:
            std::cout << "Enter word to search: ";
            std::getline(std::cin, word);
            service.searchForWord(word);
            break;
        case 4:
            service.displayWordsPerLevel();
            break;
        case 5:
            service.displayAllWords();
            break;
        case 6:
            service.displayStatistics();
            break;
    }
}
