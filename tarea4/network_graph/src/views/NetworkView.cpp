#include "../../includes/views/NetworkView.h"
#include <iostream>

void NetworkView::displayMenu() {
    std::cout << "\n=== COMPUTER NETWORK GRAPH ===\n";
    std::cout << "1. Add computer\n";
    std::cout << "2. Connect two computers\n";
    std::cout << "3. Find update propagation path (BFS)\n";
    std::cout << "4. Calculate minimum hops between computers\n";
    std::cout << "5. Display all computers\n";
    std::cout << "6. Display network configuration\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

void NetworkView::execute() {
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

void NetworkView::pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
