#ifndef TASK_VIEW_H
#define TASK_VIEW_H

#include "Task.h"
#include <vector>
#include <string>

class TaskController;

class TaskView {
public:
    static void showMenu();
    static void showPendingTasks(const TaskArray& tasks);
    static void showMessage(const std::string& message);
    static void showError(const std::string& error);
    static void showSuccess(const std::string& success);
    static void showExecutionTimes(long long insertTime, long long removeTime, 
                                 long long getPendingTime, long long markCompletedTime, 
                                 long long totalTime);
    static std::string getTaskName();
    static int getTaskPriority();
    static int getUserChoice();
    static void waitForUser();
    static void run(TaskController& controller);
};

#endif