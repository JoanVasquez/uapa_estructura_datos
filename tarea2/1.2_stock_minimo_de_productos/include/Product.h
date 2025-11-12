#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

const int MAX_PRODUCTS = 100;
const int MIN_STOCK = 5;

struct Product {
    std::string code;
    std::string name;
    int quantity;
    Product* next;
    Product* prev;
    
    Product(const std::string& c, const std::string& n, int q) 
        : code(c), name(n), quantity(q), next(nullptr), prev(nullptr) {}
};

struct ProductArray {
    Product* products[MAX_PRODUCTS];
    int count;
    
    ProductArray() : count(0) {
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            products[i] = nullptr;
        }
    }
};

#endif