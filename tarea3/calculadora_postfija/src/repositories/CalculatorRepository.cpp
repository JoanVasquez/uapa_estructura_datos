#include "repositories/CalculatorRepository.h"
#include <sstream>
#include <cmath>
#include <cctype>

CalculatorRepository::CalculatorRepository() {}

bool CalculatorRepository::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/" || 
           token == "^" || token == "sqrt";
}

bool CalculatorRepository::isNumber(const std::string& token) const {
    if (token.empty()) return false;
    
    bool hasDecimal = false;
    bool hasDigit = false;
    
    for (size_t i = 0; i < token.length(); i++) {
        char c = token[i];
        
        if (i == 0 && (c == '+' || c == '-')) {
            continue;
        }
        
        if (c == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        } else {
            return false;
        }
    }
    
    return hasDigit;
}

double CalculatorRepository::performOperation(double a, double b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Division por cero");
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::runtime_error("Operador no soportado");
    }
}

int CalculatorRepository::getOperatorPrecedence(char op) const {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

double CalculatorRepository::evaluatePostfix(const std::string& expression, bool& success, std::string& errorMessage) {
    operandStack.clear();
    success = false;
    
    if (expression.empty()) {
        errorMessage = "Expresion vacia";
        return 0;
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isNumber(token)) {
            double number = std::stod(token);
            if (!operandStack.push(number)) {
                errorMessage = "Error: Pila llena";
                return 0;
            }
        }
        else if (isOperator(token)) {
            if (token == "sqrt") {
                // Operador unario
                double operand;
                if (!operandStack.pop(operand)) {
                    errorMessage = "Error: Expresion invalida - faltan operandos para sqrt";
                    return 0;
                }
                if (operand < 0) {
                    errorMessage = "Error: Raiz cuadrada de numero negativo";
                    return 0;
                }
                if (!operandStack.push(std::sqrt(operand))) {
                    errorMessage = "Error: Pila llena";
                    return 0;
                }
            } else {
                // Operador binario
                double b, a;
                if (!operandStack.pop(b) || !operandStack.pop(a)) {
                    errorMessage = "Error: Expresion invalida - faltan operandos";
                    return 0;
                }
                
                try {
                    double result = performOperation(a, b, token[0]);
                    if (!operandStack.push(result)) {
                        errorMessage = "Error: Pila llena";
                        return 0;
                    }
                } catch (const std::exception& e) {
                    errorMessage = e.what();
                    return 0;
                }
            }
        }
        else {
            errorMessage = "Error: Token no reconocido: " + token;
            return 0;
        }
    }
    
    double finalResult;
    if (!operandStack.pop(finalResult)) {
        errorMessage = "Error: Expresion invalida - no hay resultado";
        return 0;
    }
    
    if (!operandStack.isEmpty()) {
        errorMessage = "Error: Expresion invalida - operandos sobrantes";
        return 0;
    }
    
    success = true;
    return finalResult;
}

bool CalculatorRepository::validateExpression(const std::string& expression, std::string& errorMessage) {
    bool success;
    evaluatePostfix(expression, success, errorMessage);
    return success;
}
