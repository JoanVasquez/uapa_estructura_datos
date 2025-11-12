#ifndef TASK_SERVICE_H
#define TASK_SERVICE_H

#include "ITaskRepository.h"
#include "TaskRepository.h"
#include <memory>

struct ServiceTimes {
    long long insertTime = 0;
    long long removeTime = 0;
    long long getPendingTime = 0;
    long long markCompletedTime = 0;
};

class TaskService {
private:
    std::unique_ptr<ITaskRepository> repository;
    
public:
    explicit TaskService(std::unique_ptr<ITaskRepository> repo);
    
    void addTask(const std::string& name, int priority);
    void completeTask(const std::string& name);
    void removeCompletedTasks();
    TaskArray getPendingTasks();
    bool isValidPriority(int priority) const;
    bool taskExists(const std::string& name) const;
    ServiceTimes getExecutionTimes() const;
};

#endif