#include "../../includes/services/OfficeNetworkService.h"
#include <iostream>

void OfficeNetworkService::addOffice(std::string name) {
    repository.addOffice(name);
    std::cout << "Office '" << name << "' added to network.\n";
}

void OfficeNetworkService::addConnection(std::string office1, std::string office2) {
    repository.addConnection(office1, office2);
    std::cout << "Connection established between '" << office1 << "' and '" << office2 << "'.\n";
}

void OfficeNetworkService::displayAdjacencyList() {
    std::vector<std::string> adjacencyList = repository.getAdjacencyList();
    
    if (adjacencyList.empty()) {
        std::cout << "No offices in the network.\n";
        return;
    }
    
    std::cout << "=== ADJACENCY LIST ===\n";
    for (const std::string& officeInfo : adjacencyList) {
        std::cout << officeInfo << "\n";
    }
}

void OfficeNetworkService::displayBFSDeliveryOrder(std::string startOffice) {
    std::vector<std::string> deliveryOrder = repository.getBFSDeliveryOrder(startOffice);
    
    if (deliveryOrder.empty()) {
        std::cout << "Office '" << startOffice << "' not found or network is empty.\n";
        return;
    }
    
    std::cout << "=== BFS DELIVERY ORDER FROM '" << startOffice << "' ===\n";
    for (size_t i = 0; i < deliveryOrder.size(); i++) {
        std::cout << "Step " << i + 1 << ": Deliver to " << deliveryOrder[i] << "\n";
    }
    std::cout << "Total offices reached: " << deliveryOrder.size() << "\n";
}

void OfficeNetworkService::displayNetworkInformation() {
    int totalOffices = repository.getTotalOffices();
    
    if (totalOffices == 0) {
        std::cout << "Network is empty.\n";
        return;
    }
    
    std::cout << "=== NETWORK INFORMATION ===\n";
    std::cout << "Total offices: " << totalOffices << "\n";
    
    displayAdjacencyList();
    std::cout << "\n";
    
    if (totalOffices > 0) {
        displayBFSDeliveryOrder("Office0");
    }
}

void OfficeNetworkService::clearNetwork() {
    repository.clearNetwork();
    std::cout << "Network cleared.\n";
}
