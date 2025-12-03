#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <vector>

class Computer {
public:
    std::string name;
    std::vector<int> connections;
    
    Computer(std::string n);
    void addConnection(int computerIndex);
    bool isConnectedTo(int computerIndex);
};

#endif
