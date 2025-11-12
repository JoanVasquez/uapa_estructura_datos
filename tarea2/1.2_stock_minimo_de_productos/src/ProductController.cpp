#include "../include/ProductController.h"

ProductController::ProductController(std::unique_ptr<ProductService> productService) 
    : service(std::move(productService)) {}

void ProductController::addProduct(const std::string& code, const std::string& name, int quantity) {
    service->addProduct(code, name, quantity);
}

ProductArray ProductController::getLowStockProducts() {
    return service->getLowStockProducts();
}

bool ProductController::updateStock(const std::string& code, int newQuantity) {
    return service->updateStock(code, newQuantity);
}

ExecutionTimes ProductController::getExecutionTimes() const {
    auto serviceTimes = service->getExecutionTimes();
    return {
        serviceTimes.insertTime,
        serviceTimes.getLowStockTime,
        serviceTimes.updateStockTime
    };
}