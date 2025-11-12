#include "../include/ProductRepository.h"

ProductRepository::ProductRepository() : head(nullptr), tail(nullptr) {}

ProductRepository::~ProductRepository() {
    clear();
}

void ProductRepository::insert(const std::string& code, const std::string& name, int quantity) {
    auto start = std::chrono::high_resolution_clock::now();
    
    Product* newProduct = new Product(code, name, quantity);
    
    if (!head) {
        head = tail = newProduct;
    } else {
        tail->next = newProduct;
        newProduct->prev = tail;
        tail = newProduct;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    insertTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

ProductArray ProductRepository::getLowStockProducts() {
    auto start = std::chrono::high_resolution_clock::now();
    
    ProductArray lowStockProducts;
    Product* current = head;
    
    while (current && lowStockProducts.count < MAX_PRODUCTS) {
        if (current->quantity < MIN_STOCK) {
            lowStockProducts.products[lowStockProducts.count] = current;
            lowStockProducts.count++;
        }
        current = current->next;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    getLowStockTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    return lowStockProducts;
}

bool ProductRepository::updateStock(const std::string& code, int newQuantity) {
    auto start = std::chrono::high_resolution_clock::now();
    
    Product* current = head;
    bool found = false;
    
    while (current) {
        if (current->code == code) {
            current->quantity = newQuantity;
            found = true;
            break;
        }
        current = current->next;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    updateStockTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    return found;
}

ProductArray ProductRepository::getAllProducts() {
    ProductArray allProducts;
    Product* current = head;
    
    while (current && allProducts.count < MAX_PRODUCTS) {
        allProducts.products[allProducts.count] = current;
        allProducts.count++;
        current = current->next;
    }
    
    return allProducts;
}

void ProductRepository::clear() {
    while (head) {
        Product* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

ProductRepository::RepoTimes ProductRepository::getExecutionTimes() const {
    return {
        insertTime.count(),
        getLowStockTime.count(),
        updateStockTime.count()
    };
}