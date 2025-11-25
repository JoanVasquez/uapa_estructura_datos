#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include "services/PostfixService.h"
#include <string>

class CalculatorController {
private:
    PostfixService* service;

    void displayMenu() const;
    void processChoice(int choice);
    void evaluateExpression();
    void showHelp() const;
    void showExamples() const;
    int getValidatedInput() const;

public:
    CalculatorController(PostfixService* calcService);
    ~CalculatorController();
    
    void run();
};

#endif
