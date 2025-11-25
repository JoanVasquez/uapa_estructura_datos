#include "entities/Product.h"
#include <sstream>
#include <iomanip>

Product::Product(const std::string& productName, int productQuantity, double productPrice) 
    : name(productName), quantity(productQuantity), price(productPrice) {}

std::string Product::getName() const {
    return name;
}

int Product::getQuantity() const {
    return quantity;
}

double Product::getPrice() const {
    return price;
}

double Product::getTotalPrice() const {
    return quantity * price;
}

void Product::setQuantity(int newQuantity) {
    if (newQuantity >= 0) {
        quantity = newQuantity;
    }
}

void Product::setPrice(double newPrice) {
    if (newPrice >= 0) {
        price = newPrice;
    }
}

void Product::increaseQuantity(int amount) {
    if (amount > 0) {
        quantity += amount;
    }
}

std::string Product::toString() const {
    std::ostringstream oss;
    oss << quantity << " " << name;
    if (price > 0) {
        oss << " - $" << std::fixed << std::setprecision(2) << getTotalPrice();
    }
    return oss.str();
}

std::string Product::toReceiptString() const {
    std::ostringstream oss;
    oss << std::left << std::setw(20) << name 
        << std::right << std::setw(3) << quantity 
        << " x $" << std::setw(6) << std::fixed << std::setprecision(2) << price
        << " = $" << std::setw(8) << getTotalPrice();
    return oss.str();
}

bool Product::isValid() const {
    return !name.empty() && quantity > 0 && price >= 0;
}
