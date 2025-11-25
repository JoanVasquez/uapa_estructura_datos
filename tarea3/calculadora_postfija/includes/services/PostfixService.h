#ifndef POSTFIXSERVICE_H
#define POSTFIXSERVICE_H

#include "repositories/CalculatorRepository.h"
#include <string>

class PostfixService {
private:
    CalculatorRepository* repository;

public:
    PostfixService(CalculatorRepository* repo);
    ~PostfixService();
    
    double evaluateExpression(const std::string& expression, bool& success, std::string& errorMessage);
    bool validateExpression(const std::string& expression, std::string& errorMessage);
    std::string formatResult(double result) const;
};

#endif
