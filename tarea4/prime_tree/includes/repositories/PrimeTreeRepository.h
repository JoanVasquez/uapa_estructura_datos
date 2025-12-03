#ifndef PRIMETREEREPOSITORY_H
#define PRIMETREEREPOSITORY_H

#include "../entities/TreeNode.h"

class PrimeTreeRepository {
private:
    TreeNode* root;
    
    bool isPrime(int n);
    int* generateFirstNPrimes(int n);
    TreeNode* insertNode(TreeNode* node, int value);
    void inorderTraversal(TreeNode* node);
    int countLeafNodes(TreeNode* node);
    int calculateHeight(TreeNode* node);

public:
    PrimeTreeRepository();
    ~PrimeTreeRepository();
    void buildPrimeTree();
    void displayInorder();
    int getLeafCount();
    int getTreeHeight();
    
private:
    void destroyTree(TreeNode* node);
};

#endif
