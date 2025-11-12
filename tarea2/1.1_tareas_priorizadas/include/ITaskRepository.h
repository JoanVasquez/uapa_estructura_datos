#ifndef ITASK_REPOSITORY_H
#define ITASK_REPOSITORY_H

#include "Task.h"

class ITaskRepository {
public:
    virtual ~ITaskRepository() = default;
    virtual void insert(const std::string& name, int priority) = 0;
    virtual void remove(const std::string& name) = 0;
    virtual TaskArray getPendingTasks() = 0;
    virtual TaskArray getAllTasks() = 0;
    virtual void markAsCompleted(const std::string& name) = 0;
    virtual void clear() = 0;
};

#endif