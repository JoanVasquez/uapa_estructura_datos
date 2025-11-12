#ifndef PRODUCT_SERVICE_H
#define PRODUCT_SERVICE_H

#include "IProductRepository.h"
#include "ProductRepository.h"
#include <memory>

struct ServiceTimes {
    long long insertTime = 0;
    long long getLowStockTime = 0;
    long long updateStockTime = 0;
};

class ProductService {
private:
    std::unique_ptr<IProductRepository> repository;
    
public:
    explicit ProductService(std::unique_ptr<IProductRepository> repo);
    
    void addProduct(const std::string& code, const std::string& name, int quantity);
    ProductArray getLowStockProducts();
    bool updateStock(const std::string& code, int newQuantity);
    bool isValidQuantity(int quantity) const;
    bool productExists(const std::string& code) const;
    ServiceTimes getExecutionTimes() const;
};

#endif