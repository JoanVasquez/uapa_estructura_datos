#include "../../includes/controllers/NetworkController.h"
#include <iostream>

void NetworkController::executeOption(int option) {
    std::string computer1, computer2;
    
    switch (option) {
        case 1:
            std::cout << "Enter computer name: ";
            std::getline(std::cin, computer1);
            service.addComputer(computer1);
            break;
        case 2:
            std::cout << "Enter first computer name: ";
            std::getline(std::cin, computer1);
            std::cout << "Enter second computer name: ";
            std::getline(std::cin, computer2);
            service.connectComputers(computer1, computer2);
            break;
        case 3:
            std::cout << "Enter starting computer: ";
            std::getline(std::cin, computer1);
            std::cout << "Enter target computer: ";
            std::getline(std::cin, computer2);
            service.displayUpdatePropagation(computer1, computer2);
            break;
        case 4:
            std::cout << "Enter first computer: ";
            std::getline(std::cin, computer1);
            std::cout << "Enter second computer: ";
            std::getline(std::cin, computer2);
            service.displayMinimumHops(computer1, computer2);
            break;
        case 5:
            service.displayAllComputers();
            break;
        case 6:
            service.displayNetwork();
            break;
    }
}
