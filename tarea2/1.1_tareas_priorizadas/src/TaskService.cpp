#include "../include/TaskService.h"
#include <stdexcept>

TaskService::TaskService(std::unique_ptr<ITaskRepository> repo) 
    : repository(std::move(repo)) {}

void TaskService::addTask(const std::string& name, int priority) {
    if (!isValidPriority(priority)) {
        throw std::invalid_argument("Prioridad debe ser entre 1 y 10");
    }
    
    if (taskExists(name)) {
        throw std::invalid_argument("La tarea ya existe");
    }
    
    repository->insert(name, priority);
}

void TaskService::completeTask(const std::string& name) {
    if (!taskExists(name)) {
        throw std::invalid_argument("La tarea no existe");
    }
    
    repository->markAsCompleted(name);
}

void TaskService::removeCompletedTasks() {
    // Implementación simplificada - en un caso real se eliminarían las completadas
    // Por ahora solo marca como completadas
}

TaskArray TaskService::getPendingTasks() {
    return repository->getPendingTasks();
}

bool TaskService::isValidPriority(int priority) const {
    return priority >= 1 && priority <= 10;
}

bool TaskService::taskExists(const std::string& name) const {
    auto tasks = repository->getAllTasks();
    for (int i = 0; i < tasks.count; i++) {
        if (tasks.tasks[i]->name == name) {
            return true;
        }
    }
    return false;
}

ServiceTimes TaskService::getExecutionTimes() const {
    // Obtener tiempos del repositorio si es TaskRepository
    if (auto* taskRepo = dynamic_cast<TaskRepository*>(repository.get())) {
        auto repoTimes = taskRepo->getExecutionTimes();
        return {
            repoTimes.insertTime,
            repoTimes.removeTime,
            repoTimes.getPendingTime,
            repoTimes.markCompletedTime
        };
    }
    return {0, 0, 0, 0};
}