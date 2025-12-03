#include "../../includes/views/OfficeNetworkView.h"
#include <iostream>

void OfficeNetworkView::displayMenu() {
    std::cout << "\n=== OFFICE DOCUMENT DISTRIBUTION NETWORK ===\n";
    std::cout << "1. Add office\n";
    std::cout << "2. Add connection between offices\n";
    std::cout << "3. Display adjacency list\n";
    std::cout << "4. Display BFS delivery order from specific office\n";
    std::cout << "5. Display complete network information\n";
    std::cout << "6. Clear network\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

void OfficeNetworkView::execute() {
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

void OfficeNetworkView::pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
