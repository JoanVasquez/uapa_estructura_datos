#ifndef TASK_REPOSITORY_H
#define TASK_REPOSITORY_H

#include "ITaskRepository.h"
#include <chrono>

class TaskRepository : public ITaskRepository {
private:
    Task* head;
    Task* tail;
    
public:
    TaskRepository();
    ~TaskRepository();
    
    void insert(const std::string& name, int priority) override;
    void remove(const std::string& name) override;
    TaskArray getPendingTasks() override;
    TaskArray getAllTasks() override;
    void markAsCompleted(const std::string& name) override;
    void clear() override;
    
    // Métodos para medición de tiempo
    std::chrono::microseconds insertTime;
    std::chrono::microseconds removeTime;
    std::chrono::microseconds getPendingTime;
    std::chrono::microseconds markCompletedTime;
    
    struct RepoTimes {
        long long insertTime;
        long long removeTime;
        long long getPendingTime;
        long long markCompletedTime;
    };
    
    RepoTimes getExecutionTimes() const;
};

#endif