#include "../../includes/repositories/NetworkRepository.h"
#include <iostream>
#include <queue>
#include <algorithm>

NetworkRepository::NetworkRepository() {}

int NetworkRepository::findComputerIndex(std::string name) {
    for (size_t i = 0; i < computers.size(); i++) {
        if (computers[i].name == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void NetworkRepository::addComputer(std::string name) {
    if (findComputerIndex(name) == -1) {
        computers.push_back(Computer(name));
    }
}

void NetworkRepository::connectComputers(std::string computer1, std::string computer2) {
    int index1 = findComputerIndex(computer1);
    int index2 = findComputerIndex(computer2);
    
    if (index1 == -1 || index2 == -1) {
        return;
    }
    
    computers[index1].addConnection(index2);
    computers[index2].addConnection(index1);
}

std::vector<int> NetworkRepository::bfsPath(int start, int target) {
    std::vector<int> path;
    if (start < 0 || target < 0 || start >= static_cast<int>(computers.size()) || target >= static_cast<int>(computers.size())) {
        return path;
    }
    
    std::vector<bool> visited(computers.size(), false);
    std::vector<int> parent(computers.size(), -1);
    std::queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == target) {
            int node = target;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
        
        for (int neighbor : computers[current].connections) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    return path;
}

std::vector<std::string> NetworkRepository::getUpdatePropagationPath(std::string startComputer, std::string targetComputer) {
    std::vector<std::string> path;
    int start = findComputerIndex(startComputer);
    int target = findComputerIndex(targetComputer);
    
    if (start == -1 || target == -1) {
        return path;
    }
    
    std::vector<int> nodePath = bfsPath(start, target);
    
    for (int nodeIndex : nodePath) {
        path.push_back(computers[nodeIndex].name);
    }
    
    return path;
}

int NetworkRepository::getMinimumHops(std::string computer1, std::string computer2) {
    int index1 = findComputerIndex(computer1);
    int index2 = findComputerIndex(computer2);
    
    if (index1 == -1 || index2 == -1) {
        return -1;
    }
    
    std::vector<int> path = bfsPath(index1, index2);
    
    if (path.empty()) {
        return -1;
    }
    
    return static_cast<int>(path.size()) - 1;
}

std::vector<std::string> NetworkRepository::getAllComputers() {
    std::vector<std::string> computerNames;
    for (const Computer& computer : computers) {
        computerNames.push_back(computer.name);
    }
    return computerNames;
}

int NetworkRepository::getTotalComputers() {
    return static_cast<int>(computers.size());
}

void NetworkRepository::displayNetwork() {
    std::cout << "Network Configuration:\n";
    for (size_t i = 0; i < computers.size(); i++) {
        std::cout << computers[i].name << " -> ";
        for (size_t j = 0; j < computers[i].connections.size(); j++) {
            std::cout << computers[computers[i].connections[j]].name;
            if (j < computers[i].connections.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
}
