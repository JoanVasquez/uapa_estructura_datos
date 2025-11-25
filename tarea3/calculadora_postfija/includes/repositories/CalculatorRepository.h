#ifndef CALCULATORREPOSITORY_H
#define CALCULATORREPOSITORY_H

#include "entities/Stack.h"
#include <string>

class CalculatorRepository {
private:
    Stack operandStack;

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    double performOperation(double a, double b, char op) const;
    int getOperatorPrecedence(char op) const;

public:
    CalculatorRepository();
    
    double evaluatePostfix(const std::string& expression, bool& success, std::string& errorMessage);
    bool validateExpression(const std::string& expression, std::string& errorMessage);
};

#endif
