#include "../../includes/views/TemperatureView.h"
#include <iostream>

void TemperatureView::displayMenu() {
    std::cout << "\n=== TEMPERATURE CONTROL SYSTEM ===\n";
    std::cout << "1. Add temperature record\n";
    std::cout << "2. Display records sorted by temperature\n";
    std::cout << "3. Search temperature by date\n";
    std::cout << "4. Calculate average temperature (recursive)\n";
    std::cout << "5. Display all temperature records\n";
    std::cout << "6. Display temperature statistics\n";
    std::cout << "7. Clear all records\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

void TemperatureView::execute() {
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

void TemperatureView::pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}
