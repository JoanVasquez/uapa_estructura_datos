#ifndef OFFICE_H
#define OFFICE_H

#include <string>
#include <vector>

class Office {
public:
    std::string name;
    std::vector<int> connections;
    
    Office(std::string n);
    void addConnection(int officeIndex);
    bool isConnectedTo(int officeIndex);
};

#endif
