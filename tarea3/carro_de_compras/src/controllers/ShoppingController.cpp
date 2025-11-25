#include "controllers/ShoppingController.h"
#include <iostream>
#include <limits>
#include <iomanip>

ShoppingController::ShoppingController(ShoppingService* shopService) 
    : service(shopService) {}

ShoppingController::~ShoppingController() {
    delete service;
}

void ShoppingController::displayMenu() const {
    std::cout << "\n=== CARRITO DE COMPRAS ONLINE ===\n";
    std::cout << "1. Agregar producto al carrito\n";
    std::cout << "2. Procesar pago\n";
    std::cout << "3. Ver carrito\n";
    std::cout << "4. Resumen del carrito\n";
    std::cout << "5. Mostrar ayuda\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opcion (1-6): ";
}

void ShoppingController::processChoice(int choice) {
    switch (choice) {
        case 1:
            addProductToCart();
            break;
        case 2:
            processPayment();
            break;
        case 3:
            viewCart();
            break;
        case 4:
            showCartSummary();
            break;
        case 5:
            showHelp();
            break;
        case 6:
            std::cout << "Saliendo del sistema de compras...\n";
            break;
        default:
            std::cout << "Opcion invalida. Por favor seleccione 1-6.\n";
    }
}

void ShoppingController::addProductToCart() {
    std::string productName;
    int quantity;
    double price;
    
    std::cout << "Ingrese el nombre del producto: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, productName);
    
    if (productName.empty()) {
        std::cout << "Error: El nombre del producto no puede estar vacio\n";
        return;
    }
    
    std::cout << "Ingrese la cantidad: ";
    if (!(std::cin >> quantity) || quantity <= 0) {
        std::cout << "Error: Cantidad invalida\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    std::cout << "Ingrese el precio unitario (0 si no aplica): $";
    price = getValidatedPrice();
    
    if (service->addToCart(productName, quantity, price)) {
        std::cout << "Producto agregado al carrito: " << quantity << " " << productName << "\n";
        std::cout << service->getCartSummary() << "\n";
    } else {
        std::cout << "Error: No se pudo agregar el producto (carrito lleno o datos invalidos)\n";
    }
}

void ShoppingController::processPayment() {
    if (service->isCartEmpty()) {
        std::cout << "El carrito esta vacio. Agregue productos antes de pagar.\n";
        return;
    }
    
    std::string receipt;
    if (service->processPayment(receipt)) {
        std::cout << "\nPago procesado exitosamente!\n";
        std::cout << receipt << "\n";
    } else {
        std::cout << receipt << "\n";
    }
}

void ShoppingController::viewCart() {
    std::cout << "\n" << service->viewCart() << "\n";
}

void ShoppingController::showCartSummary() const {
    std::cout << "\n=== RESUMEN DEL CARRITO ===\n";
    std::cout << service->getCartSummary() << "\n";
    
    if (service->isCartEmpty()) {
        std::cout << "Estado: Carrito vacio\n";
    } else {
        std::cout << "Total a pagar: $" << std::fixed << std::setprecision(2) 
                  << service->getTotalAmount() << "\n";
    }
}

void ShoppingController::showHelp() const {
    std::cout << "\n=== AYUDA - CARRITO DE COMPRAS ===\n";
    std::cout << "Este sistema simula el proceso de compras online.\n\n";
    std::cout << "FUNCIONALIDADES:\n";
    std::cout << "• Agregar producto: Anade productos al carrito\n";
    std::cout << "• Procesar pago: Finaliza la compra y genera recibo\n";
    std::cout << "• Ver carrito: Muestra todos los productos en el carrito\n";
    std::cout << "• Resumen: Muestra estadisticas del carrito\n\n";
    std::cout << "CARACTERISTICAS:\n";
    std::cout << "• Los productos se agrupan automaticamente\n";
    std::cout << "• Calculo automatico de totales\n";
    std::cout << "• Capacidad maxima: 50 productos diferentes\n";
    std::cout << "• El carrito se vacia automaticamente despues del pago\n";
}

int ShoppingController::getValidatedInput() const {
    int choice;
    std::cin >> choice;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    
    return choice;
}

double ShoppingController::getValidatedPrice() const {
    double price;
    if (!(std::cin >> price) || price < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0.0;
    }
    return price;
}

void ShoppingController::run() {
    int choice = 0;
    
    std::cout << "Sistema de Carrito de Compras Iniciado\n";
    
    do {
        displayMenu();
        choice = getValidatedInput();
        
        if (choice == -1) {
            std::cout << "Entrada invalida. Por favor ingrese un numero.\n";
            continue;
        }
        
        processChoice(choice);
        
    } while (choice != 6);
}
