#include "controllers/CalculatorController.h"
#include <iostream>
#include <limits>
#include <sstream>

CalculatorController::CalculatorController(PostfixService* calcService) 
    : service(calcService) {}

CalculatorController::~CalculatorController() {
    delete service;
}

void CalculatorController::displayMenu() const {
    std::cout << "\n=== CALCULADORA POSTFIJA ===\n";
    std::cout << "1. Evaluar expresion postfija\n";
    std::cout << "2. Mostrar ejemplos\n";
    std::cout << "3. Mostrar ayuda\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opcion (1-4): ";
}

void CalculatorController::processChoice(int choice) {
    switch (choice) {
        case 1:
            evaluateExpression();
            break;
        case 2:
            showExamples();
            break;
        case 3:
            showHelp();
            break;
        case 4:
            std::cout << "Saliendo de la calculadora...\n";
            break;
        default:
            std::cout << "❌ Opcion invalida. Por favor seleccione 1-4.\n";
    }
}

void CalculatorController::evaluateExpression() {
    std::string expression;
    std::cout << "Ingrese la expresion postfija: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, expression);
    
    if (expression.empty()) {
        std::cout << "❌ Error: La expresion no puede estar vacia\n";
        return;
    }
    
    bool success;
    std::string errorMessage;
    double result = service->evaluateExpression(expression, success, errorMessage);
    
    if (success) {
        std::cout << "✅ Resultado: " << service->formatResult(result) << "\n";
    } else {
        std::cout << "❌ " << errorMessage << "\n";
    }
}

void CalculatorController::showHelp() const {
    std::cout << "\n=== AYUDA - CALCULADORA POSTFIJA ===\n";
    std::cout << "La notacion postfija (o RPN) coloca los operadores despues de los operandos.\n\n";
    std::cout << "OPERADORES SOPORTADOS:\n";
    std::cout << "  +   : Suma\n";
    std::cout << "  -   : Resta\n";
    std::cout << "  *   : Multiplicacion\n";
    std::cout << "  /   : Division\n";
    std::cout << "  ^   : Potencia\n";
    std::cout << "  sqrt : Raiz cuadrada (operador unario)\n\n";
    std::cout << "INSTRUCCIONES:\n";
    std::cout << "• Separe cada token con espacios\n";
    std::cout << "• Use numeros enteros o decimales\n";
    std::cout << "• Los operadores deben tener operandos suficientes\n";
}

void CalculatorController::showExamples() const {
    std::cout << "\n=== EJEMPLOS DE EXPRESIONES POSTFIJAS ===\n";
    
    struct Example {
        std::string expression;
        std::string description;
    };
    
    Example examples[] = {
        {"3 4 +", "Suma: 3 + 4 = 7"},
        {"5 2 -", "Resta: 5 - 2 = 3"},
        {"3 4 + 2 *", "Combinada: (3 + 4) * 2 = 14"},
        {"10 5 /", "Division: 10 / 5 = 2"},
        {"2 3 ^", "Potencia: 2^3 = 8"},
        {"16 sqrt", "Raiz cuadrada: √16 = 4"},
        {"3 4 2 * 1 5 - 2 3 ^ ^ / +", "Compleja: 3 + (4*2) / (1-5)^(2^3)"},
        {"5 1 2 + 4 * + 3 -", "5 + ((1 + 2) * 4) - 3 = 14"}
    };
    
    for (const auto& example : examples) {
        std::cout << "• " << example.expression << "  →  " << example.description << "\n";
    }
    
    std::cout << "\nEjemplo con error:\n";
    std::cout << "• 3 +  →  Error: expresion invalida - faltan operandos\n";
}

int CalculatorController::getValidatedInput() const {
    int choice;
    std::cin >> choice;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    
    return choice;
}

void CalculatorController::run() {
    int choice = 0;
    
    std::cout << "🧮 Calculadora Postfija Iniciada\n";
    
    do {
        displayMenu();
        choice = getValidatedInput();
        
        if (choice == -1) {
            std::cout << "❌ Entrada invalida. Por favor ingrese un numero.\n";
            continue;
        }
        
        processChoice(choice);
        
    } while (choice != 4);
}
