#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "ProductService.h"
#include <memory>

struct ExecutionTimes {
    long long insertTime = 0;
    long long getLowStockTime = 0;
    long long updateStockTime = 0;
};

class ProductController {
private:
    std::unique_ptr<ProductService> service;
    
public:
    explicit ProductController(std::unique_ptr<ProductService> productService);
    
    void addProduct(const std::string& code, const std::string& name, int quantity);
    ProductArray getLowStockProducts();
    bool updateStock(const std::string& code, int newQuantity);
    ExecutionTimes getExecutionTimes() const;
};

#endif