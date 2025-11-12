#ifndef PRODUCT_VIEW_H
#define PRODUCT_VIEW_H

#include "Product.h"
#include <string>

class ProductController;

class ProductView {
public:
    static void showMenu();
    static void showLowStockProducts(const ProductArray& products);
    static void showMessage(const std::string& message);
    static void showError(const std::string& error);
    static void showSuccess(const std::string& success);
    static void showExecutionTimes(long long insertTime, long long getLowStockTime, 
                                 long long updateStockTime, long long totalTime);
    static std::string getProductCode();
    static std::string getProductName();
    static int getProductQuantity();
    static int getUserChoice();
    static void waitForUser();
    static void run(ProductController& controller);
};

#endif