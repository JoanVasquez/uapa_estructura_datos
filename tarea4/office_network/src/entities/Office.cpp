#include "../../includes/entities/Office.h"
#include <algorithm>

Office::Office(std::string n) : name(n) {}

void Office::addConnection(int officeIndex) {
    if (std::find(connections.begin(), connections.end(), officeIndex) == connections.end()) {
        connections.push_back(officeIndex);
    }
}

bool Office::isConnectedTo(int officeIndex) {
    return std::find(connections.begin(), connections.end(), officeIndex) != connections.end();
}
