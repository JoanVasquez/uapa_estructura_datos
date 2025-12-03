#include "../../includes/views/PrimeTreeView.h"
#include <iostream>
#include <limits>

void PrimeTreeView::displayMenu() {
    std::cout << "\n=== PRIME NUMBER TREE ===\n";
    std::cout << "1. Build tree with first 15 prime numbers\n";
    std::cout << "2. Display primes in inorder\n";
    std::cout << "3. Calculate number of leaf nodes\n";
    std::cout << "4. Determine height of the tree\n";
    std::cout << "5. Display all information\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

void PrimeTreeView::execute() {
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

void PrimeTreeView::pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
