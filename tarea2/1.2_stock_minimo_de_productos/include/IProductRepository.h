#ifndef IPRODUCT_REPOSITORY_H
#define IPRODUCT_REPOSITORY_H

#include "Product.h"

class IProductRepository {
public:
    virtual ~IProductRepository() = default;
    virtual void insert(const std::string& code, const std::string& name, int quantity) = 0;
    virtual ProductArray getLowStockProducts() = 0;
    virtual bool updateStock(const std::string& code, int newQuantity) = 0;
    virtual ProductArray getAllProducts() = 0;
    virtual void clear() = 0;
};

#endif