#include "controllers/NavigationController.h"
#include "services/NavigationService.h"
#include "repositories/HistoryRepository.h"
#include "views/NavigationView.h"
#include <iostream>

int main() {
    NavigationView::displayWelcome();
    
    try {
        HistoryRepository* repository = new HistoryRepository();
        NavigationService* service = new NavigationService(repository);
        NavigationController* controller = new NavigationController(service);
        
        controller->run();
        
        delete controller;
        
    } catch (const std::exception& e) {
        std::cout << "💥 Error critico: " << e.what() << "\n";
        return 1;
    }
    
    NavigationView::displayGoodbye();
    return 0;
}
