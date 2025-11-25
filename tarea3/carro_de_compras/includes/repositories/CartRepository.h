#ifndef CARTREPOSITORY_H
#define CARTREPOSITORY_H

#include "entities/Product.h"

class CartRepository {
private:
    static const int MAX_CART_SIZE = 50;
    Product* cart[MAX_CART_SIZE];
    int itemCount;

    int findProductIndex(const std::string& productName) const;

public:
    CartRepository();
    ~CartRepository();
    
    bool addProduct(const std::string& productName, int quantity, double price = 0.0);
    bool removeProduct(const std::string& productName);
    bool updateProductQuantity(const std::string& productName, int newQuantity);
    Product* getProduct(const std::string& productName) const;
    Product** getAllProducts(int& productCount) const;
    double getTotalAmount() const;
    int getTotalItems() const;
    int getProductCount() const;
    bool isEmpty() const;
    bool isFull() const;
    void clearCart();
};

#endif
