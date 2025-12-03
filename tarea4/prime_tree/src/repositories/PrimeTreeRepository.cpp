#include "../../includes/repositories/PrimeTreeRepository.h"
#include <iostream>
#include <cmath>

PrimeTreeRepository::PrimeTreeRepository() : root(nullptr) {}

PrimeTreeRepository::~PrimeTreeRepository() {
    destroyTree(root);
}

bool PrimeTreeRepository::isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int* PrimeTreeRepository::generateFirstNPrimes(int n) {
    int* primes = new int[n];
    int count = 0;
    int num = 2;
    
    while (count < n) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;
        }
        num++;
    }
    return primes;
}

TreeNode* PrimeTreeRepository::insertNode(TreeNode* node, int value) {
    if (!node) {
        return new TreeNode(value);
    }
    
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }
    
    return node;
}

void PrimeTreeRepository::buildPrimeTree() {
    int* primes = generateFirstNPrimes(15);
    
    for (int i = 0; i < 15; i++) {
        root = insertNode(root, primes[i]);
    }
    
    delete[] primes;
}

void PrimeTreeRepository::displayInorder() {
    inorderTraversal(root);
}

void PrimeTreeRepository::inorderTraversal(TreeNode* node) {
    if (!node) return;
    
    inorderTraversal(node->left);
    std::cout << node->value << " ";
    inorderTraversal(node->right);
}

int PrimeTreeRepository::countLeafNodes(TreeNode* node) {
    if (!node) return 0;
    
    if (!node->left && !node->right) {
        return 1;
    }
    
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int PrimeTreeRepository::getLeafCount() {
    return countLeafNodes(root);
}

int PrimeTreeRepository::calculateHeight(TreeNode* node) {
    if (!node) return 0;
    
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    
    return std::max(leftHeight, rightHeight) + 1;
}

int PrimeTreeRepository::getTreeHeight() {
    return calculateHeight(root);
}

void PrimeTreeRepository::destroyTree(TreeNode* node) {
    if (!node) return;
    
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
