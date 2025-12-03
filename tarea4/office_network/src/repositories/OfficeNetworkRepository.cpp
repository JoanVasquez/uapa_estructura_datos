#include "../../includes/repositories/OfficeNetworkRepository.h"
#include <iostream>
#include <queue>
#include <algorithm>

OfficeNetworkRepository::OfficeNetworkRepository() {}

int OfficeNetworkRepository::findOfficeIndex(std::string name) {
    for (size_t i = 0; i < offices.size(); i++) {
        if (offices[i].name == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool OfficeNetworkRepository::isValidOfficeIndex(int index) {
    return index >= 0 && index < static_cast<int>(offices.size());
}

void OfficeNetworkRepository::addOffice(std::string name) {
    if (findOfficeIndex(name) == -1) {
        offices.push_back(Office(name));
    }
}

void OfficeNetworkRepository::addConnection(std::string office1, std::string office2) {
    int index1 = findOfficeIndex(office1);
    int index2 = findOfficeIndex(office2);
    
    if (index1 == -1 || index2 == -1) {
        return;
    }
    
    offices[index1].addConnection(index2);
    offices[index2].addConnection(index1);
}

std::vector<std::string> OfficeNetworkRepository::getBFSDeliveryOrder(std::string startOffice) {
    std::vector<std::string> deliveryOrder;
    int startIndex = findOfficeIndex(startOffice);
    
    if (startIndex == -1 || offices.empty()) {
        return deliveryOrder;
    }
    
    std::vector<bool> visited(offices.size(), false);
    std::queue<int> q;
    
    visited[startIndex] = true;
    q.push(startIndex);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        deliveryOrder.push_back(offices[current].name);
        
        for (int neighbor : offices[current].connections) {
            if (isValidOfficeIndex(neighbor) && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return deliveryOrder;
}

std::vector<std::string> OfficeNetworkRepository::getAdjacencyList() {
    std::vector<std::string> adjacencyList;
    
    for (size_t i = 0; i < offices.size(); i++) {
        std::string officeInfo = offices[i].name + " -> ";
        
        for (size_t j = 0; j < offices[i].connections.size(); j++) {
            int neighborIndex = offices[i].connections[j];
            if (isValidOfficeIndex(neighborIndex)) {
                officeInfo += offices[neighborIndex].name;
                if (j < offices[i].connections.size() - 1) {
                    officeInfo += ", ";
                }
            }
        }
        
        adjacencyList.push_back(officeInfo);
    }
    
    return adjacencyList;
}

int OfficeNetworkRepository::getTotalOffices() {
    return static_cast<int>(offices.size());
}

void OfficeNetworkRepository::clearNetwork() {
    offices.clear();
}
