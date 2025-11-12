#include "../include/TaskRepository.h"

TaskRepository::TaskRepository() : head(nullptr), tail(nullptr) {}

TaskRepository::~TaskRepository() {
    clear();
}

void TaskRepository::insert(const std::string& name, int priority) {
    auto start = std::chrono::high_resolution_clock::now();
    
    Task* newTask = new Task(name, priority);
    
    if (!head) {
        head = tail = newTask;
    } else {
        Task* current = head;
        while (current && current->priority >= priority) {
            current = current->next;
        }
        
        if (!current) {
            // Insertar al final
            tail->next = newTask;
            newTask->prev = tail;
            tail = newTask;
        } else if (current == head) {
            // Insertar al inicio
            newTask->next = head;
            head->prev = newTask;
            head = newTask;
        } else {
            // Insertar en el medio
            newTask->next = current;
            newTask->prev = current->prev;
            current->prev->next = newTask;
            current->prev = newTask;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    insertTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

void TaskRepository::remove(const std::string& name) {
    auto start = std::chrono::high_resolution_clock::now();
    
    Task* current = head;
    while (current) {
        if (current->name == name) {
            if (current == head && current == tail) {
                head = tail = nullptr;
            } else if (current == head) {
                head = current->next;
                head->prev = nullptr;
            } else if (current == tail) {
                tail = current->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            break;
        }
        current = current->next;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    removeTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

TaskArray TaskRepository::getPendingTasks() {
    auto start = std::chrono::high_resolution_clock::now();
    
    TaskArray pendingTasks;
    Task* current = head;
    
    while (current && pendingTasks.count < MAX_TASKS) {
        if (current->status == TaskStatus::PENDING) {
            pendingTasks.tasks[pendingTasks.count] = current;
            pendingTasks.count++;
        }
        current = current->next;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    getPendingTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    return pendingTasks;
}

TaskArray TaskRepository::getAllTasks() {
    TaskArray allTasks;
    Task* current = head;
    
    while (current && allTasks.count < MAX_TASKS) {
        allTasks.tasks[allTasks.count] = current;
        allTasks.count++;
        current = current->next;
    }
    
    return allTasks;
}

void TaskRepository::markAsCompleted(const std::string& name) {
    auto start = std::chrono::high_resolution_clock::now();
    
    Task* current = head;
    while (current) {
        if (current->name == name) {
            current->status = TaskStatus::COMPLETED;
            break;
        }
        current = current->next;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    markCompletedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

void TaskRepository::clear() {
    while (head) {
        Task* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

TaskRepository::RepoTimes TaskRepository::getExecutionTimes() const {
    return {
        insertTime.count(),
        removeTime.count(),
        getPendingTime.count(),
        markCompletedTime.count()
    };
}