#include "controllers/NavigationController.h"
#include <iostream>
#include <sstream>
#include <limits>

NavigationController::NavigationController(NavigationService* navService) 
    : service(navService) {}

NavigationController::~NavigationController() {
    delete service;
}

void NavigationController::displayMenu() const {
    std::cout << "\n=== SISTEMA DE NAVEGACION WEB ===\n";
    std::cout << "1. Visitar nueva pagina\n";
    std::cout << "2. Ir hacia atras\n";
    std::cout << "3. Ir hacia adelante\n";
    std::cout << "4. Mostrar estado actual\n";
    std::cout << "5. Mostrar ayuda\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opcion (1-6): ";
}

void NavigationController::processChoice(int choice) {
    switch (choice) {
        case 1:
            processVisit();
            break;
        case 2:
            if (service->back()) {
                std::cout << "✅ Navegando hacia atras\n";
                showCurrentStatus();
            } else {
                std::cout << "❌ No hay paginas en el historial atras\n";
            }
            break;
        case 3:
            if (service->forward()) {
                std::cout << "✅ Navegando hacia adelante\n";
                showCurrentStatus();
            } else {
                std::cout << "❌ No hay paginas en el historial adelante\n";
            }
            break;
        case 4:
            showCurrentStatus();
            break;
        case 5:
            showHelp();
            break;
        case 6:
            std::cout << "Saliendo del sistema de navegacion...\n";
            break;
        default:
            std::cout << "❌ Opcion invalida. Por favor seleccione 1-6.\n";
    }
}

void NavigationController::processVisit() {
    std::string url;
    std::cout << "Ingrese la URL a visitar: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, url);
    
    // Eliminar espacios en blanco al inicio y final
    url.erase(0, url.find_first_not_of(" \t"));
    url.erase(url.find_last_not_of(" \t") + 1);
    
    if (url.empty()) {
        std::cout << "❌ Error: La URL no puede estar vacia\n";
        return;
    }
    
    if (service->visit(url)) {
        std::cout << "✅ Visitando: " << url << "\n";
        showCurrentStatus();
    } else {
        std::cout << "❌ Error: No se pudo visitar la pagina\n";
    }
}

void NavigationController::showHelp() const {
    std::cout << "\n=== AYUDA - SISTEMA DE NAVEGACION ===\n";
    std::cout << "Este sistema simula el comportamiento de un navegador web\n";
    std::cout << "con las funciones de avanzar y retroceder.\n\n";
    std::cout << "FUNCIONALIDADES:\n";
    std::cout << "• Visitar nueva pagina: Agrega una pagina al historial\n";
    std::cout << "• Ir hacia atras: Regresa a la pagina anterior\n";
    std::cout << "• Ir hacia adelante: Avanza a la pagina siguiente\n";
    std::cout << "• Mostrar estado: Muestra la pagina actual y historiales\n";
    std::cout << "• Salir: Termina el programa\n\n";
    std::cout << "EJEMPLO DE USO:\n";
    std::cout << "1. Visitar 'google.com'\n";
    std::cout << "2. Visitar 'uapa.edu.do'\n";
    std::cout << "3. Visitar 'github.com'\n";
    std::cout << "4. Ir hacia atras (uapa.edu.do)\n";
    std::cout << "5. Ir hacia atras (google.com)\n";
    std::cout << "6. Ir hacia adelante (uapa.edu.do)\n";
    std::cout << "7. Mostrar estado actual\n";
}

void NavigationController::showCurrentStatus() const {
    std::cout << "\n=== ESTADO ACTUAL DE NAVEGACION ===\n";
    std::cout << service->getFullStatus() << "\n";
}

int NavigationController::getValidatedInput() const {
    int choice;
    std::cin >> choice;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1; // Indicador de entrada inválida
    }
    
    return choice;
}

void NavigationController::run() {
    int choice = 0;
    
    std::cout << "🚀 Sistema de Navegacion Web Iniciado\n";
    
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
