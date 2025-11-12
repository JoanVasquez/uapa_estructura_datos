#include "../include/TaskView.h"
#include "../include/TaskController.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

void TaskView::showMenu() {
    std::cout << "\n=== SISTEMA DE TAREAS PRIORIZADAS ===\n";
    std::cout << "1. Agregar tarea\n";
    std::cout << "2. Mostrar tareas pendientes\n";
    std::cout << "3. Marcar tarea como completada\n";
    std::cout << "4. Eliminar tareas completadas\n";
    std::cout << "5. Salir\n";
    std::cout << "=====================================\n";
}

void TaskView::showPendingTasks(const TaskArray& tasks) {
    std::cout << "\n=== TAREAS PENDIENTES ===\n";
    
    if (tasks.count == 0) {
        std::cout << "No hay tareas pendientes.\n";
        return;
    }
    
    std::cout << std::left << std::setw(20) << "Nombre" 
              << std::setw(10) << "Prioridad" 
              << std::setw(12) << "Estado" << "\n";
    std::cout << std::string(42, '-') << "\n";
    
    for (int i = 0; i < tasks.count; i++) {
        std::cout << std::left << std::setw(20) << tasks.tasks[i]->name
                  << std::setw(10) << tasks.tasks[i]->priority
                  << std::setw(12) << "Pendiente" << "\n";
    }
    std::cout << "========================\n";
}

void TaskView::showMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void TaskView::showError(const std::string& error) {
    std::cout << "ERROR: " << error << std::endl;
}

void TaskView::showSuccess(const std::string& success) {
    std::cout << "ÉXITO: " << success << std::endl;
}

void TaskView::showExecutionTimes(long long insertTime, long long removeTime, 
                                long long getPendingTime, long long markCompletedTime, 
                                long long totalTime) {
    std::cout << "\n=== TIEMPOS DE EJECUCION ===\n";
    std::cout << "Insertar tarea: " << insertTime << " microsegundos\n";
    std::cout << "Eliminar tarea: " << removeTime << " microsegundos\n";
    std::cout << "Obtener pendientes: " << getPendingTime << " microsegundos\n";
    std::cout << "Marcar completada: " << markCompletedTime << " microsegundos\n";
    std::cout << "Tiempo total: " << totalTime << " microsegundos\n";
    std::cout << "============================\n";
}

std::string TaskView::getTaskName() {
    std::string name;
    std::cout << "Ingrese el nombre de la tarea: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    return name;
}

int TaskView::getTaskPriority() {
    int priority;
    std::cout << "Ingrese la prioridad (1-10): ";
    std::cin >> priority;
    return priority;
}

int TaskView::getUserChoice() {
    int choice;
    std::cout << "Seleccione una opcion: ";
    std::cin >> choice;
    return choice;
}

void TaskView::waitForUser() {
    std::cout << "\nPresione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void TaskView::run(TaskController& controller) {
    int choice;
    
    do {
        showMenu();
        choice = getUserChoice();
        
        try {
            switch (choice) {
                case 1: {
                    std::string name = getTaskName();
                    int priority = getTaskPriority();
                    controller.addTask(name, priority);
                    showSuccess("Tarea agregada exitosamente");
                    break;
                }
                case 2: {
                    auto tasks = controller.getPendingTasks();
                    showPendingTasks(tasks);
                    break;
                }
                case 3: {
                    std::string name = getTaskName();
                    controller.completeTask(name);
                    showSuccess("Tarea marcada como completada");
                    break;
                }
                case 4:
                    controller.removeCompletedTasks();
                    showSuccess("Tareas completadas eliminadas");
                    break;
                case 5:
                    showMessage("Saliendo del programa...");
                    break;
                default:
                    showError("Opcion invalida");
                    break;
            }
        } catch (const std::exception& e) {
            showError(e.what());
        }
        
        if (choice != 5) {
            waitForUser();
        }
        
    } while (choice != 5);
}