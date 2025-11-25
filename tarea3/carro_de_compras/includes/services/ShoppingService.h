#ifndef SHOPPINGSERVICE_H
#define SHOPPINGSERVICE_H

#include "repositories/CartRepository.h"
#include <string>

class ShoppingService {
private:
    CartRepository* repository;

public:
    ShoppingService(CartRepository* repo);
    ~ShoppingService();
    
    bool addToCart(const std::string& productName, int quantity, double price = 0.0);
    bool processPayment(std::string& receipt);
    std::string viewCart() const;
    std::string getCartSummary() const;
    double getTotalAmount() const;
    int getTotalItems() const;
    int getProductCount() const;
    bool isCartEmpty() const;
    void clearCart();
};

#endif
