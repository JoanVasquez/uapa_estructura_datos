#include "services/PostfixService.h"
#include <sstream>
#include <iomanip>

PostfixService::PostfixService(CalculatorRepository* repo) : repository(repo) {}

PostfixService::~PostfixService() {
    delete repository;
}

double PostfixService::evaluateExpression(const std::string& expression, bool& success, std::string& errorMessage) {
    return repository->evaluatePostfix(expression, success, errorMessage);
}

bool PostfixService::validateExpression(const std::string& expression, std::string& errorMessage) {
    return repository->validateExpression(expression, errorMessage);
}

std::string PostfixService::formatResult(double result) const {
    std::ostringstream oss;
    
    // Si el resultado es entero, mostrarlo sin decimales
    if (result == static_cast<int>(result)) {
        oss << static_cast<int>(result);
    } else {
        oss << std::fixed << std::setprecision(6) << result;
        // Eliminar ceros innecesarios al final
        std::string str = oss.str();
        size_t dotPos = str.find('.');
        if (dotPos != std::string::npos) {
            // Eliminar ceros al final
            str = str.substr(0, str.find_last_not_of('0') + 1);
            // Si solo queda el punto decimal, eliminarlo también
            if (str.back() == '.') {
                str.pop_back();
            }
        }
        return str;
    }
    
    return oss.str();
}
