#ifndef NETWORKREPOSITORY_H
#define NETWORKREPOSITORY_H

#include "../entities/Computer.h"
#include <string>
#include <vector>
#include <queue>

class NetworkRepository {
private:
    std::vector<Computer> computers;
    
    int findComputerIndex(std::string name);
    std::vector<int> bfsPath(int start, int target);
    
public:
    NetworkRepository();
    void addComputer(std::string name);
    void connectComputers(std::string computer1, std::string computer2);
    std::vector<std::string> getUpdatePropagationPath(std::string startComputer, std::string targetComputer);
    int getMinimumHops(std::string computer1, std::string computer2);
    std::vector<std::string> getAllComputers();
    int getTotalComputers();
    void displayNetwork();
};

#endif
