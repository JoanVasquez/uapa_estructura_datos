#include "controllers/PackingController.h"
#include "services/PackingService.h"
#include "repositories/QueueRepository.h"
#include "views/PackingView.h"
#include <iostream>

int main() {
    PackingView::displayWelcome();
    
    try {
        QueueRepository* repository = new QueueRepository();
        PackingService* service = new PackingService(repository);
        PackingController* controller = new PackingController(service);
        
        controller->run();
        
        delete controller;
        
    } catch (const std::exception& e) {
        std::cout << "💥 Error critico: " << e.what() << "\n";
        return 1;
    }
    
    PackingView::displayGoodbye();
    return 0;
}
