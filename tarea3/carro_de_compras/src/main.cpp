#include "controllers/ShoppingController.h"
#include "services/ShoppingService.h"
#include "repositories/CartRepository.h"
#include "views/ShoppingView.h"
#include <iostream>

int main() {
    ShoppingView::displayWelcome();
    
    try {
        CartRepository* repository = new CartRepository();
        ShoppingService* service = new ShoppingService(repository);
        ShoppingController* controller = new ShoppingController(service);
        
        controller->run();
        
        delete controller;
        
    } catch (const std::exception& e) {
        std::cout << "Error critico: " << e.what() << "\n";
        return 1;
    }
    
    ShoppingView::displayGoodbye();
    return 0;
}
