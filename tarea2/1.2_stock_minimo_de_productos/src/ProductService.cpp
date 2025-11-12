#include "../include/ProductService.h"
#include <stdexcept>

ProductService::ProductService(std::unique_ptr<IProductRepository> repo) 
    : repository(std::move(repo)) {}

void ProductService::addProduct(const std::string& code, const std::string& name, int quantity) {
    if (!isValidQuantity(quantity)) {
        throw std::invalid_argument("Cantidad debe ser mayor o igual a 0");
    }
    
    if (productExists(code)) {
        throw std::invalid_argument("El producto ya existe");
    }
    
    repository->insert(code, name, quantity);
}

ProductArray ProductService::getLowStockProducts() {
    return repository->getLowStockProducts();
}

bool ProductService::updateStock(const std::string& code, int newQuantity) {
    if (!isValidQuantity(newQuantity)) {
        throw std::invalid_argument("Cantidad debe ser mayor o igual a 0");
    }
    
    return repository->updateStock(code, newQuantity);
}

bool ProductService::isValidQuantity(int quantity) const {
    return quantity >= 0;
}

bool ProductService::productExists(const std::string& code) const {
    auto products = repository->getAllProducts();
    for (int i = 0; i < products.count; i++) {
        if (products.products[i]->code == code) {
            return true;
        }
    }
    return false;
}

ServiceTimes ProductService::getExecutionTimes() const {
    if (auto* productRepo = dynamic_cast<ProductRepository*>(repository.get())) {
        auto repoTimes = productRepo->getExecutionTimes();
        return {
            repoTimes.insertTime,
            repoTimes.getLowStockTime,
            repoTimes.updateStockTime
        };
    }
    return {0, 0, 0};
}