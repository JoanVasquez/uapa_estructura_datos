#ifndef PRIMETREESERVICE_H
#define PRIMETREESERVICE_H

#include "../repositories/PrimeTreeRepository.h"

class PrimeTreeService {
private:
    PrimeTreeRepository repository;

public:
    void buildTree();
    void displayPrimesInorder();
    void displayLeafCount();
    void displayTreeHeight();
    void displayAllInformation();
};

#endif
