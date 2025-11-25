#ifndef PACKINGCONTROLLER_H
#define PACKINGCONTROLLER_H

#include "services/PackingService.h"
#include <string>

class PackingController {
private:
    PackingService* service;

    void displayMenu() const;
    void processChoice(int choice);
    void addBox();
    void processBox();
    void viewQueue();
    void showStatistics() const;
    void showHelp() const;
    int getValidatedInput() const;

public:
    PackingController(PackingService* packService);
    ~PackingController();
    
    void run();
};

#endif
