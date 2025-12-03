#ifndef OFFICENETWORKREPOSITORY_H
#define OFFICENETWORKREPOSITORY_H

#include "../entities/Office.h"
#include <string>
#include <vector>
#include <queue>

class OfficeNetworkRepository {
private:
    std::vector<Office> offices;
    
    int findOfficeIndex(std::string name);
    bool isValidOfficeIndex(int index);
    
public:
    OfficeNetworkRepository();
    void addOffice(std::string name);
    void addConnection(std::string office1, std::string office2);
    std::vector<std::string> getBFSDeliveryOrder(std::string startOffice);
    std::vector<std::string> getAdjacencyList();
    int getTotalOffices();
    void clearNetwork();
};

#endif
