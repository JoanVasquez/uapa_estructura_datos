#include "../include/TaskController.h"
#include "../include/TaskService.h"
#include "../include/TaskRepository.h"
#include "../include/TaskView.h"
#include <memory>
#include <chrono>

int main() {
    auto startTotal = std::chrono::high_resolution_clock::now();
    
    try {
        // Inyección de dependencias siguiendo principios SOLID
        auto repository = std::make_unique<TaskRepository>();
        auto service = std::make_unique<TaskService>(std::move(repository));
        auto controller = std::make_unique<TaskController>(std::move(service));
        
        // Ejecutar la aplicación desde la vista
        TaskView::run(*controller);
        
        auto endTotal = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(endTotal - startTotal);
        
        // Obtener tiempos a través del controlador (arquitectura correcta)
        auto times = controller->getExecutionTimes();
        TaskView::showExecutionTimes(
            times.insertTime,
            times.removeTime,
            times.getPendingTime,
            times.markCompletedTime,
            totalTime.count()
        );
        
    } catch (const std::exception& e) {
        TaskView::showError("Error crítico: " + std::string(e.what()));
        return 1;
    }
    
    return 0;
}