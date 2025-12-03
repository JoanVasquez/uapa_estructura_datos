#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include "../repositories/NetworkRepository.h"
#include <string>
#include <vector>

class NetworkService {
private:
    NetworkRepository repository;

public:
    void addComputer(std::string name);
    void connectComputers(std::string computer1, std::string computer2);
    void displayUpdatePropagation(std::string startComputer, std::string targetComputer);
    void displayMinimumHops(std::string computer1, std::string computer2);
    void displayAllComputers();
    void displayNetwork();
};

#endif
