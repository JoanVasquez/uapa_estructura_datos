#ifndef SHOPPINGCONTROLLER_H
#define SHOPPINGCONTROLLER_H

#include "services/ShoppingService.h"
#include <string>

class ShoppingController {
private:
    ShoppingService* service;

    void displayMenu() const;
    void processChoice(int choice);
    void addProductToCart();
    void processPayment();
    void viewCart();
    void showCartSummary() const;
    void showHelp() const;
    int getValidatedInput() const;
    double getValidatedPrice() const;

public:
    ShoppingController(ShoppingService* shopService);
    ~ShoppingController();
    
    void run();
};

#endif
