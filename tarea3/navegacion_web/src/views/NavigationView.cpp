#include "views/NavigationView.h"
#include <iostream>

void NavigationView::displayWelcome() {
    std::cout << "========================================\n";
    std::cout << "     🌐 SISTEMA DE NAVEGACION WEB 🌐\n";
    std::cout << "========================================\n";
    std::cout << "  Simulador de Navegador (Atras/Adelante)\n";
    std::cout << "========================================\n";
}

void NavigationView::displayGoodbye() {
    std::cout << "========================================\n";
    std::cout << "     👋 SESION DE NAVEGACION FINALIZADA\n";
    std::cout << "========================================\n";
}

void NavigationView::displayError(const std::string& message) {
    std::cout << "❌ Error: " << message << "\n";
}

void NavigationView::displaySuccess(const std::string& message) {
    std::cout << "✅ " << message << "\n";
}

void NavigationView::displayMenu() {
    std::cout << "\n=== MENU PRINCIPAL ===\n";
    std::cout << "1. Visitar nueva pagina\n";
    std::cout << "2. Ir atras\n";
    std::cout << "3. Ir adelante\n";
    std::cout << "4. Mostrar estado actual\n";
    std::cout << "5. Ayuda\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opcion: ";
}
