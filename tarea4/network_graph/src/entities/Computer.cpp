#include "../../includes/entities/Computer.h"
#include <algorithm>

Computer::Computer(std::string n) : name(n) {}

void Computer::addConnection(int computerIndex) {
    if (std::find(connections.begin(), connections.end(), computerIndex) == connections.end()) {
        connections.push_back(computerIndex);
    }
}

bool Computer::isConnectedTo(int computerIndex) {
    return std::find(connections.begin(), connections.end(), computerIndex) != connections.end();
}
