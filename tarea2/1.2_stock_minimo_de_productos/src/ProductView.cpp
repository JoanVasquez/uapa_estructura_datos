#include "../include/ProductView.h"
#include "../include/ProductController.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

void ProductView::showMenu() {
    std::cout << "\n=== SISTEMA DE INVENTARIO - STOCK MINIMO ===\n";
    std::cout << "1. Agregar producto\n";
    std::cout << "2. Mostrar productos con stock bajo (< 5)\n";
    std::cout << "3. Actualizar stock de producto\n";
    std::cout << "4. Salir\n";
    std::cout << "==========================================\n";
}

void ProductView::showLowStockProducts(const ProductArray& products) {
    std::cout << "\n=== PRODUCTOS CON STOCK BAJO (< 5) ===\n";
    
    if (products.count == 0) {
        std::cout << "No hay productos con stock bajo.\n";
        return;
    }
    
    std::cout << std::left << std::setw(10) << "Código" 
              << std::setw(20) << "Nombre" 
              << std::setw(10) << "Stock" << "\n";
    std::cout << std::string(40, '-') << "\n";
    
    for (int i = 0; i < products.count; i++) {
        std::cout << std::left << std::setw(10) << products.products[i]->code
                  << std::setw(20) << products.products[i]->name
                  << std::setw(10) << products.products[i]->quantity << "\n";
    }
    std::cout << "=====================================\n";
}

void ProductView::showMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void ProductView::showError(const std::string& error) {
    std::cout << "ERROR: " << error << std::endl;
}

void ProductView::showSuccess(const std::string& success) {
    std::cout << "ÉXITO: " << success << std::endl;
}

void ProductView::showExecutionTimes(long long insertTime, long long getLowStockTime, 
                                   long long updateStockTime, long long totalTime) {
    std::cout << "\n=== TIEMPOS DE EJECUCION ===\n";
    std::cout << "Insertar producto: " << insertTime << " microsegundos\n";
    std::cout << "Obtener stock bajo: " << getLowStockTime << " microsegundos\n";
    std::cout << "Actualizar stock: " << updateStockTime << " microsegundos\n";
    std::cout << "Tiempo total: " << totalTime << " microsegundos\n";
    std::cout << "============================\n";
}

std::string ProductView::getProductCode() {
    std::string code;
    std::cout << "Ingrese el código del producto: ";
    std::cin.ignore();
    std::getline(std::cin, code);
    return code;
}

std::string ProductView::getProductName() {
    std::string name;
    std::cout << "Ingrese el nombre del producto: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    return name;
}

int ProductView::getProductQuantity() {
    int quantity;
    std::cout << "Ingrese la cantidad: ";
    std::cin >> quantity;
    return quantity;
}

int ProductView::getUserChoice() {
    int choice;
    std::cout << "Seleccione una opcion: ";
    std::cin >> choice;
    return choice;
}

void ProductView::waitForUser() {
    std::cout << "\nPresione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void ProductView::run(ProductController& controller) {
    int choice;
    
    do {
        showMenu();
        choice = getUserChoice();
        
        try {
            switch (choice) {
                case 1: {
                    std::string code = getProductCode();
                    std::string name = getProductName();
                    int quantity = getProductQuantity();
                    controller.addProduct(code, name, quantity);
                    showSuccess("Producto agregado exitosamente");
                    break;
                }
                case 2: {
                    auto products = controller.getLowStockProducts();
                    showLowStockProducts(products);
                    break;
                }
                case 3: {
                    std::string code = getProductCode();
                    int quantity = getProductQuantity();
                    if (controller.updateStock(code, quantity)) {
                        showSuccess("Stock actualizado exitosamente");
                    } else {
                        showError("Producto no encontrado");
                    }
                    break;
                }
                case 4:
                    showMessage("Saliendo del programa...");
                    break;
                default:
                    showError("Opcion invalida");
                    break;
            }
        } catch (const std::exception& e) {
            showError(e.what());
        }
        
        if (choice != 4) {
            waitForUser();
        }
        
    } while (choice != 4);
}