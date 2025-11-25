#include "views/CalculatorView.h"
#include <iostream>

void CalculatorView::displayWelcome() {
    std::cout << "========================================\n";
    std::cout << "        🧮 CALCULADORA POSTFIJA 🧮\n";
    std::cout << "========================================\n";
    std::cout << "    Evaluador de Notacion Polaca Inversa\n";
    std::cout << "========================================\n";
}

void CalculatorView::displayGoodbye() {
    std::cout << "========================================\n";
    std::cout << "        👋 CALCULADORA FINALIZADA\n";
    std::cout << "========================================\n";
}
