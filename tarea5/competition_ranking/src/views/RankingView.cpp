#include "../../includes/views/RankingView.h"
#include <iostream>

void RankingView::displayMenu() {
    std::cout << "\n=== COMPETITION RANKING SYSTEM ===\n";
    std::cout << "1. Add participant\n";
    std::cout << "2. Display ranking (sorted by score)\n";
    std::cout << "3. Search participant by name\n";
    std::cout << "4. Calculate average score (recursive)\n";
    std::cout << "5. Display all participants\n";
    std::cout << "6. Display statistics\n";
    std::cout << "7. Clear all participants\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

void RankingView::execute() {
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

void RankingView::pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
