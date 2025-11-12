#include "../include/ProductController.h"
#include "../include/ProductService.h"
#include "../include/ProductRepository.h"
#include "../include/ProductView.h"
#include <memory>
#include <chrono>

int main() {
    auto startTotal = std::chrono::high_resolution_clock::now();
    
    try {
        auto repository = std::make_unique<ProductRepository>();
        auto service = std::make_unique<ProductService>(std::move(repository));
        auto controller = std::make_unique<ProductController>(std::move(service));
        
        ProductView::run(*controller);
        
        auto endTotal = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(endTotal - startTotal);
        
        auto times = controller->getExecutionTimes();
        ProductView::showExecutionTimes(
            times.insertTime,
            times.getLowStockTime,
            times.updateStockTime,
            totalTime.count()
        );
        
    } catch (const std::exception& e) {
        ProductView::showError("Error crítico: " + std::string(e.what()));
        return 1;
    }
    
    return 0;
}