#ifndef TASK_H
#define TASK_H

#include <string>

const int MAX_TASKS = 100;

enum class TaskStatus {
    PENDING,
    COMPLETED
};

struct Task {
    std::string name;
    int priority;
    TaskStatus status;
    Task* next;
    Task* prev;
    
    Task(const std::string& n, int p, TaskStatus s = TaskStatus::PENDING) 
        : name(n), priority(p), status(s), next(nullptr), prev(nullptr) {}
};

struct TaskArray {
    Task* tasks[MAX_TASKS];
    int count;
    
    TaskArray() : count(0) {
        for (int i = 0; i < MAX_TASKS; i++) {
            tasks[i] = nullptr;
        }
    }
};

#endif