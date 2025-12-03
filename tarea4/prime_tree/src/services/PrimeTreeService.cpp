#include "../../includes/services/PrimeTreeService.h"
#include <iostream>

void PrimeTreeService::buildTree() {
    repository.buildPrimeTree();
    std::cout << "Prime number tree built successfully with first 15 prime numbers.\n";
}

void PrimeTreeService::displayPrimesInorder() {
    std::cout << "Prime numbers in inorder traversal: ";
    repository.displayInorder();
    std::cout << std::endl;
}

void PrimeTreeService::displayLeafCount() {
    int leafCount = repository.getLeafCount();
    std::cout << "Number of leaf nodes: " << leafCount << std::endl;
}

void PrimeTreeService::displayTreeHeight() {
    int height = repository.getTreeHeight();
    std::cout << "Height of the tree: " << height << std::endl;
}

void PrimeTreeService::displayAllInformation() {
    displayPrimesInorder();
    displayLeafCount();
    displayTreeHeight();
}
