#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    int quantity;
    double price;

public:
    Product(const std::string& productName, int productQuantity, double productPrice = 0.0);
    
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    double getTotalPrice() const;
    void setQuantity(int newQuantity);
    void setPrice(double newPrice);
    void increaseQuantity(int amount = 1);
    std::string toString() const;
    std::string toReceiptString() const;
    bool isValid() const;
};

#endif
