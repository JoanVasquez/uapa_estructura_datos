#include "../include/TaskService.h"
#include "../include/TaskRepository.h"
#include "../include/TaskView.h"
#include <memory>
#include <chrono>
#include <iostream>

void demoProgram() {
    auto startTotal = std::chrono::high_resolution_clock::now();
    
    std::cout << "=== DEMOSTRACIÓN DEL SISTEMA DE TAREAS PRIORIZADAS ===\n\n";
    
    // Crear servicio para demo
    auto repository = std::make_unique<TaskRepository>();
    auto service = std::make_unique<TaskService>(std::move(repository));
    
    // Demostrar inserción ordenada por prioridad
    std::cout << "1. Insertando tareas con diferentes prioridades:\n";
    service->addTask("Estudiar para examen", 9);
    service->addTask("Hacer compras", 3);
    service->addTask("Proyecto urgente", 10);
    service->addTask("Llamar al médico", 7);
    service->addTask("Limpiar casa", 2);
    
    std::cout << "   - Estudiar para examen (prioridad 9)\n";
    std::cout << "   - Hacer compras (prioridad 3)\n";
    std::cout << "   - Proyecto urgente (prioridad 10)\n";
    std::cout << "   - Llamar al médico (prioridad 7)\n";
    std::cout << "   - Limpiar casa (prioridad 2)\n\n";
    
    // Mostrar tareas ordenadas
    std::cout << "2. Tareas ordenadas por prioridad (descendente):\n";
    auto pendingTasks = service->getPendingTasks();
    TaskView::showPendingTasks(pendingTasks);
    
    // Marcar algunas como completadas
    std::cout << "\n3. Marcando 'Hacer compras' como completada:\n";
    service->completeTask("Hacer compras");
    TaskView::showSuccess("Tarea marcada como completada");
    
    std::cout << "\n4. Marcando 'Proyecto urgente' como completada:\n";
    service->completeTask("Proyecto urgente");
    TaskView::showSuccess("Tarea marcada como completada");
    
    // Mostrar solo pendientes
    std::cout << "\n5. Tareas pendientes después de completar algunas:\n";
    pendingTasks = service->getPendingTasks();
    TaskView::showPendingTasks(pendingTasks);
    
    auto endTotal = std::chrono::high_resolution_clock::now();
    auto totalTime = std::chrono::duration_cast<std::chrono::microseconds>(endTotal - startTotal);
    
    // Mostrar tiempos de ejecución usando arquitectura correcta
    std::cout << "\n6. Análisis de rendimiento:\n";
    auto times = service->getExecutionTimes();
    TaskView::showExecutionTimes(
        times.insertTime,
        times.removeTime,
        times.getPendingTime,
        times.markCompletedTime,
        totalTime.count()
    );
    
    std::cout << "\n=== DEMOSTRACIÓN COMPLETADA ===\n";
}

int main() {
    demoProgram();
    return 0;
}