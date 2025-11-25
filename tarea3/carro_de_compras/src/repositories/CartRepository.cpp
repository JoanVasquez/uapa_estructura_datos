#include "repositories/CartRepository.h"
#include <algorithm>

CartRepository::CartRepository() : itemCount(0) {
    for (int i = 0; i < MAX_CART_SIZE; i++) {
        cart[i] = nullptr;
    }
}

CartRepository::~CartRepository() {
    clearCart();
}

int CartRepository::findProductIndex(const std::string& productName) const {
    for (int i = 0; i < itemCount; i++) {
        if (cart[i] != nullptr && cart[i]->getName() == productName) {
            return i;
        }
    }
    return -1;
}

bool CartRepository::addProduct(const std::string& productName, int quantity, double price) {
    if (isFull() || productName.empty() || quantity <= 0) {
        return false;
    }
    
    int existingIndex = findProductIndex(productName);
    if (existingIndex != -1) {
        cart[existingIndex]->increaseQuantity(quantity);
        return true;
    }
    
    cart[itemCount] = new Product(productName, quantity, price);
    itemCount++;
    return true;
}

bool CartRepository::removeProduct(const std::string& productName) {
    int index = findProductIndex(productName);
    if (index == -1) {
        return false;
    }
    
    delete cart[index];
    
    for (int i = index; i < itemCount - 1; i++) {
        cart[i] = cart[i + 1];
    }
    
    cart[itemCount - 1] = nullptr;
    itemCount--;
    return true;
}

bool CartRepository::updateProductQuantity(const std::string& productName, int newQuantity) {
    if (newQuantity <= 0) {
        return removeProduct(productName);
    }
    
    Product* product = getProduct(productName);
    if (product == nullptr) {
        return false;
    }
    
    product->setQuantity(newQuantity);
    return true;
}

Product* CartRepository::getProduct(const std::string& productName) const {
    int index = findProductIndex(productName);
    return (index != -1) ? cart[index] : nullptr;
}

Product** CartRepository::getAllProducts(int& productCount) const {
    productCount = itemCount;
    Product** products = new Product*[itemCount];
    
    for (int i = 0; i < itemCount; i++) {
        products[i] = cart[i];
    }
    
    return products;
}

double CartRepository::getTotalAmount() const {
    double total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        if (cart[i] != nullptr) {
            total += cart[i]->getTotalPrice();
        }
    }
    return total;
}

int CartRepository::getTotalItems() const {
    int totalItems = 0;
    for (int i = 0; i < itemCount; i++) {
        if (cart[i] != nullptr) {
            totalItems += cart[i]->getQuantity();
        }
    }
    return totalItems;
}

int CartRepository::getProductCount() const {
    return itemCount;
}

bool CartRepository::isEmpty() const {
    return itemCount == 0;
}

bool CartRepository::isFull() const {
    return itemCount >= MAX_CART_SIZE;
}

void CartRepository::clearCart() {
    for (int i = 0; i < itemCount; i++) {
        delete cart[i];
        cart[i] = nullptr;
    }
    itemCount = 0;
}
