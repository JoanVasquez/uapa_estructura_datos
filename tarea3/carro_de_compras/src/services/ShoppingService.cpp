#include "services/ShoppingService.h"
#include <sstream>
#include <iomanip>

ShoppingService::ShoppingService(CartRepository* repo) : repository(repo) {}

ShoppingService::~ShoppingService() {
    delete repository;
}

bool ShoppingService::addToCart(const std::string& productName, int quantity, double price) {
    return repository->addProduct(productName, quantity, price);
}

bool ShoppingService::processPayment(std::string& receipt) {
    if (repository->isEmpty()) {
        receipt = "El carrito esta vacio. No se puede procesar el pago.";
        return false;
    }
    
    std::stringstream ss;
    int productCount = 0;
    Product** products = repository->getAllProducts(productCount);
    
    ss << "=== COMPROBANTE DE PAGO ===\n";
    ss << "Productos procesados:\n";
    
    for (int i = 0; i < productCount; i++) {
        ss << "Procesando pago de " << products[i]->toString() << "\n";
    }
    
    ss << "---------------------------\n";
    ss << "Total: $" << std::fixed << std::setprecision(2) << repository->getTotalAmount() << "\n";
    ss << "Total de items: " << repository->getTotalItems() << "\n";
    ss << "Gracias por su compra!";
    
    receipt = ss.str();
    
    repository->clearCart();
    
    delete[] products;
    return true;
}

std::string ShoppingService::viewCart() const {
    int productCount = 0;
    Product** products = repository->getAllProducts(productCount);
    
    std::stringstream ss;
    
    if (productCount == 0) {
        ss << "El carrito esta vacio";
    } else {
        ss << "Carrito de Compras (" << repository->getTotalItems() << " items):\n";
        for (int i = 0; i < productCount; i++) {
            ss << "  " << (i + 1) << ". " << products[i]->toString() << "\n";
        }
        ss << "Total: $" << std::fixed << std::setprecision(2) << repository->getTotalAmount();
    }
    
    delete[] products;
    return ss.str();
}

std::string ShoppingService::getCartSummary() const {
    std::stringstream ss;
    ss << "Carrito: " << repository->getProductCount() << " productos, " 
       << repository->getTotalItems() << " items, Total: $" 
       << std::fixed << std::setprecision(2) << repository->getTotalAmount();
    return ss.str();
}

double ShoppingService::getTotalAmount() const {
    return repository->getTotalAmount();
}

int ShoppingService::getTotalItems() const {
    return repository->getTotalItems();
}

int ShoppingService::getProductCount() const {
    return repository->getProductCount();
}

bool ShoppingService::isCartEmpty() const {
    return repository->isEmpty();
}

void ShoppingService::clearCart() {
    repository->clearCart();
}
