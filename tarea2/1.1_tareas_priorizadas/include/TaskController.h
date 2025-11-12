#ifndef TASK_CONTROLLER_H
#define TASK_CONTROLLER_H

#include "TaskService.h"
#include <memory>

struct ExecutionTimes {
    long long insertTime = 0;
    long long removeTime = 0;
    long long getPendingTime = 0;
    long long markCompletedTime = 0;
};

class TaskController {
private:
    std::unique_ptr<TaskService> service;
    ExecutionTimes times;
    
public:
    explicit TaskController(std::unique_ptr<TaskService> taskService);
    
    void addTask(const std::string& name, int priority);
    TaskArray getPendingTasks();
    void completeTask(const std::string& name);
    void removeCompletedTasks();
    ExecutionTimes getExecutionTimes() const;
};

#endif