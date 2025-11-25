#include "views/PackingView.h"
#include <iostream>

void PackingView::displayWelcome() {
    std::cout << "========================================\n";
    std::cout << "     🏭 SIMULADOR DE COLA DE EMPAQUE 🏭\n";
    std::cout << "========================================\n";
    std::cout << "   Sistema de Gestion de Almacen (FIFO)\n";
    std::cout << "========================================\n";
}

void PackingView::displayGoodbye() {
    std::cout << "========================================\n";
    std::cout << "     👋 SIMULACION FINALIZADA\n";
    std::cout << "========================================\n";
}
