#ifndef PRODUCT_REPOSITORY_H
#define PRODUCT_REPOSITORY_H

#include "IProductRepository.h"
#include <chrono>

class ProductRepository : public IProductRepository {
private:
    Product* head;
    Product* tail;
    
public:
    ProductRepository();
    ~ProductRepository();
    
    void insert(const std::string& code, const std::string& name, int quantity) override;
    ProductArray getLowStockProducts() override;
    bool updateStock(const std::string& code, int newQuantity) override;
    ProductArray getAllProducts() override;
    void clear() override;
    
    std::chrono::microseconds insertTime;
    std::chrono::microseconds getLowStockTime;
    std::chrono::microseconds updateStockTime;
    
    struct RepoTimes {
        long long insertTime;
        long long getLowStockTime;
        long long updateStockTime;
    };
    
    RepoTimes getExecutionTimes() const;
};

#endif