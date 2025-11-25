#include "controllers/PackingController.h"
#include <iostream>
#include <limits>

PackingController::PackingController(PackingService* packService) 
    : service(packService) {}

PackingController::~PackingController() {
    delete service;
}

void PackingController::displayMenu() const {
    std::cout << "\n=== SIMULADOR DE COLA DE EMPAQUE ===\n";
    std::cout << "1. Agregar caja a la cola\n";
    std::cout << "2. Procesar siguiente caja\n";
    std::cout << "3. Ver cola de empaque\n";
    std::cout << "4. Mostrar estadisticas\n";
    std::cout << "5. Mostrar ayuda\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opcion (1-6): ";
}

void PackingController::processChoice(int choice) {
    switch (choice) {
        case 1:
            addBox();
            break;
        case 2:
            processBox();
            break;
        case 3:
            viewQueue();
            break;
        case 4:
            showStatistics();
            break;
        case 5:
            showHelp();
            break;
        case 6:
            std::cout << "Saliendo del simulador...\n";
            break;
        default:
            std::cout << "❌ Opcion invalida. Por favor seleccione 1-6.\n";
    }
}

void PackingController::addBox() {
    std::string description;
    std::cout << "Ingrese la descripcion de la caja: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, description);
    
    if (description.empty()) {
        std::cout << "❌ Error: La descripcion no puede estar vacia\n";
        return;
    }
    
    if (service->addBox(description)) {
        std::cout << "✅ Caja agregada exitosamente a la cola\n";
        std::cout << service->getQueueStatus() << "\n";
    } else {
        std::cout << "❌ Error: No se pudo agregar la caja (cola llena)\n";
    }
}

void PackingController::processBox() {
    std::string resultMessage;
    
    if (service->processBox(resultMessage)) {
        std::cout << "✅ " << resultMessage << "\n";
    } else {
        std::cout << "❌ " << resultMessage << "\n";
    }
    
    std::cout << service->getQueueStatus() << "\n";
}

void PackingController::viewQueue() {
    std::cout << "\n" << service->viewQueue() << "\n";
}

void PackingController::showStatistics() const {
    std::cout << "\n=== ESTADISTICAS DEL SISTEMA ===\n";
    std::cout << service->getQueueStatus() << "\n";
    std::cout << "Capacidad maxima: 100 cajas\n";
    
    if (service->isQueueEmpty()) {
        std::cout << "📊 Estado: Cola vacia - listo para recibir cajas\n";
    } else if (service->getQueueSize() < 10) {
        std::cout << "📊 Estado: Flujo normal\n";
    } else if (service->getQueueSize() < 50) {
        std::cout << "📊 Estado: Cola moderada\n";
    } else {
        std::cout << "📊 Estado: Cola congestionada\n";
    }
}

void PackingController::showHelp() const {
    std::cout << "\n=== AYUDA - SIMULADOR DE COLA DE EMPAQUE ===\n";
    std::cout << "Este sistema simula el proceso de empaque en un almacen.\n\n";
    std::cout << "FUNCIONALIDADES:\n";
    std::cout << "• Agregar caja: Añade una nueva caja al final de la cola\n";
    std::cout << "• Procesar caja: Atiende la primera caja en la cola (FIFO)\n";
    std::cout << "• Ver cola: Muestra todas las cajas en orden de llegada\n";
    std::cout << "• Estadisticas: Muestra el estado actual del sistema\n\n";
    std::cout << "CARACTERISTICAS:\n";
    std::cout << "• Cada caja recibe un ID automatico (C001, C002, etc.)\n";
    std::cout << "• Orden FIFO (First-In, First-Out)\n";
    std::cout << "• Capacidad maxima: 100 cajas\n";
    std::cout << "• Procesamiento por orden de llegada\n";
}

int PackingController::getValidatedInput() const {
    int choice;
    std::cin >> choice;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    
    return choice;
}

void PackingController::run() {
    int choice = 0;
    
    std::cout << "🏭 Simulador de Cola de Empaque Iniciado\n";
    
    do {
        displayMenu();
        choice = getValidatedInput();
        
        if (choice == -1) {
            std::cout << "❌ Entrada invalida. Por favor ingrese un numero.\n";
            continue;
        }
        
        processChoice(choice);
        
    } while (choice != 6);
}
