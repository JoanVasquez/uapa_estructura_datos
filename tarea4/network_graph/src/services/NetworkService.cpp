#include "../../includes/services/NetworkService.h"
#include <iostream>

void NetworkService::addComputer(std::string name) {
    repository.addComputer(name);
    std::cout << "Computer '" << name << "' added to network.\n";
}

void NetworkService::connectComputers(std::string computer1, std::string computer2) {
    repository.connectComputers(computer1, computer2);
    std::cout << "Connection established between '" << computer1 << "' and '" << computer2 << "'.\n";
}

void NetworkService::displayUpdatePropagation(std::string startComputer, std::string targetComputer) {
    std::vector<std::string> path = repository.getUpdatePropagationPath(startComputer, targetComputer);
    
    if (path.empty()) {
        std::cout << "No path exists between '" << startComputer << "' and '" << targetComputer << "'.\n";
        return;
    }
    
    std::cout << "Update propagation path from '" << startComputer << "' to '" << targetComputer << "':\n";
    for (size_t i = 0; i < path.size(); i++) {
        std::cout << i + 1 << ". " << path[i] << "\n";
    }
}

void NetworkService::displayMinimumHops(std::string computer1, std::string computer2) {
    int hops = repository.getMinimumHops(computer1, computer2);
    
    if (hops == -1) {
        std::cout << "No path exists between '" << computer1 << "' and '" << computer2 << "'.\n";
    } else {
        std::cout << "Minimum hops between '" << computer1 << "' and '" << computer2 << "': " << hops << "\n";
    }
}

void NetworkService::displayAllComputers() {
    std::vector<std::string> computers = repository.getAllComputers();
    
    if (computers.empty()) {
        std::cout << "No computers in the network.\n";
        return;
    }
    
    std::cout << "Computers in the network:\n";
    for (size_t i = 0; i < computers.size(); i++) {
        std::cout << i + 1 << ". " << computers[i] << "\n";
    }
    std::cout << "Total: " << computers.size() << " computer(s)\n";
}

void NetworkService::displayNetwork() {
    if (repository.getTotalComputers() == 0) {
        std::cout << "No computers in the network.\n";
        return;
    }
    
    repository.displayNetwork();
}
