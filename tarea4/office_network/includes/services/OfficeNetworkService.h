#ifndef OFFICENETWORKSERVICE_H
#define OFFICENETWORKSERVICE_H

#include "../repositories/OfficeNetworkRepository.h"
#include <string>
#include <vector>

class OfficeNetworkService {
private:
    OfficeNetworkRepository repository;

public:
    void addOffice(std::string name);
    void addConnection(std::string office1, std::string office2);
    void displayAdjacencyList();
    void displayBFSDeliveryOrder(std::string startOffice);
    void displayNetworkInformation();
    void clearNetwork();
};

#endif
