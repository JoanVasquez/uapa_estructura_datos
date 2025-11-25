#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include "services/NavigationService.h"
#include <string>

class NavigationController {
private:
    NavigationService* service;

    void displayMenu() const;
    void processChoice(int choice);
    void processVisit();
    void showHelp() const;
    void showCurrentStatus() const;
    int getValidatedInput() const;

public:
    NavigationController(NavigationService* navService);
    ~NavigationController();
    
    void run();
};

#endif
