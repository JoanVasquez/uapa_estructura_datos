#include "../../includes/controllers/OfficeNetworkController.h"
#include <iostream>

void OfficeNetworkController::executeOption(int option) {
    std::string office1, office2;
    
    switch (option) {
        case 1:
            std::cout << "Enter office name: ";
            std::getline(std::cin, office1);
            service.addOffice(office1);
            break;
        case 2:
            std::cout << "Enter first office name: ";
            std::getline(std::cin, office1);
            std::cout << "Enter second office name: ";
            std::getline(std::cin, office2);
            service.addConnection(office1, office2);
            break;
        case 3:
            service.displayAdjacencyList();
            break;
        case 4:
            std::cout << "Enter starting office name: ";
            std::getline(std::cin, office1);
            service.displayBFSDeliveryOrder(office1);
            break;
        case 5:
            service.displayNetworkInformation();
            break;
        case 6:
            service.clearNetwork();
            break;
    }
}
