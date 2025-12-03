#include "../../includes/views/WordTreeView.h"
#include <iostream>

void WordTreeView::displayMenu() {
    std::cout << "\n=== WORD TREE FOR SEARCH ENGINE ===\n";
    std::cout << "1. Insert word\n";
    std::cout << "2. Show words alphabetically (inorder)\n";
    std::cout << "3. Search for exact word\n";
    std::cout << "4. Show words per level\n";
    std::cout << "5. Display all words\n";
    std::cout << "6. Display statistics\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

void WordTreeView::execute() {
    int option;
    
    do {
        displayMenu();
        std::cin >> option;
        std::cin.ignore();
        
        if (option != 0) {
            controller.executeOption(option);
            pause();
        }
        
    } while (option != 0);
    
    std::cout << "Exiting program...\n";
}

void WordTreeView::pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
