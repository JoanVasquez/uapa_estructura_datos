#include "../include/TaskController.h"

TaskController::TaskController(std::unique_ptr<TaskService> taskService) 
    : service(std::move(taskService)) {}

void TaskController::addTask(const std::string& name, int priority) {
    service->addTask(name, priority);
}

TaskArray TaskController::getPendingTasks() {
    return service->getPendingTasks();
}

void TaskController::completeTask(const std::string& name) {
    service->completeTask(name);
}

void TaskController::removeCompletedTasks() {
    service->removeCompletedTasks();
}

ExecutionTimes TaskController::getExecutionTimes() const {
    auto serviceTimes = service->getExecutionTimes();
    return {
        serviceTimes.insertTime,
        serviceTimes.removeTime,
        serviceTimes.getPendingTime,
        serviceTimes.markCompletedTime
    };
}