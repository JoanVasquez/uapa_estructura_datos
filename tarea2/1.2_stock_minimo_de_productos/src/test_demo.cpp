#include "../include/ProductService.h"
#include "../include/ProductRepository.h"
#include "../include/ProductView.h"
#include <memory>
#include <chrono>
#include <iostream>

void demoProgram() {
    auto startTotal = std::chrono::high_resolution_clock::now();
    
    std::cout << "=== DEMOSTRACIÓN DEL SISTEMA DE INVENTARIO ===\n\n";
    
    auto repository = std::make_unique<ProductRepository>();
    auto service = std::make_unique<ProductService>(std::move(repository));
    
    std::cout << "1. Insertando productos con diferentes stocks:\n";
    service->addProduct("P001", "Arroz", 10);
    service->addProduct("P002", "Azúcar", 3);
    service->addProduct("P003", "Aceite", 8);
    service->addProduct("P004", "Sal", 2);
    service->addProduct("P005", "Harina", 15);
    
    std::cout << "   - Arroz (stock: 10)\n";
    std::cout << "   - Azúcar (stock: 3) - STOCK BAJO\n";
    std::cout << "   - Aceite (stock: 8)\n";
    std::cout << "   - Sal (stock: 2) - STOCK BAJO\n";
    std::cout << "   - Harina (stock: 15)\n\n";
    
    std::cout << "2. Productos con stock bajo (< 5 unidades):\n";
    auto lowStockProducts = service->getLowStockProducts();
    ProductView::showLowStockProducts(lowStockProducts);
    
    std::cout << "\n3. Actualizando stock de 'Azúcar' a 20 unidades:\n";
    if (service->updateStock("P002", 20)) {
        ProductView::showSuccess("Stock actualizado");
    }
    
    std::cout << "\n4. Productos con stock bajo después de actualización:\n";
    lowStockProducts = service->getLowStockProducts();
    ProductView::showLowStockProducts(lowStockProducts);
    
    auto endTotal = std::chrono::high_resolution_clock::now();
    auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(endTotal - startTotal);
    
    std::cout << "\n5. Análisis de rendimiento:\n";
    auto times = service->getExecutionTimes();
    ProductView::showExecutionTimes(
        times.insertTime,
        times.getLowStockTime,
        times.updateStockTime,
        totalTime.count()
    );
    
    std::cout << "\n=== DEMOSTRACIÓN COMPLETADA ===\n";
}

int main() {
    demoProgram();
    return 0;
}