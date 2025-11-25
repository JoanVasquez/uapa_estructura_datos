#include "controllers/CalculatorController.h"
#include "services/PostfixService.h"
#include "repositories/CalculatorRepository.h"
#include "views/CalculatorView.h"
#include <iostream>

int main() {
    CalculatorView::displayWelcome();
    
    try {
        CalculatorRepository* repository = new CalculatorRepository();
        PostfixService* service = new PostfixService(repository);
        CalculatorController* controller = new CalculatorController(service);
        
        controller->run();
        
        delete controller;
        
    } catch (const std::exception& e) {
        std::cout << "💥 Error critico: " << e.what() << "\n";
        return 1;
    }
    
    CalculatorView::displayGoodbye();
    return 0;
}
