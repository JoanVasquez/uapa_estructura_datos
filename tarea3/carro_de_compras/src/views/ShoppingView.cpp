#include "views/ShoppingView.h"
#include <iostream>

void ShoppingView::displayWelcome() {
    std::cout << "========================================\n";
    std::cout << "       CARRITO DE COMPRAS ONLINE\n";
    std::cout << "========================================\n";
    std::cout << "     Sistema de Checkout y Pagos\n";
    std::cout << "========================================\n";
}

void ShoppingView::displayGoodbye() {
    std::cout << "========================================\n";
    std::cout << "        COMPRAS FINALIZADAS\n";
    std::cout << "========================================\n";
}
