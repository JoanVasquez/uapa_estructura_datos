#ifndef NETWORKVIEW_H
#define NETWORKVIEW_H

#include "../controllers/NetworkController.h"

class NetworkView {
private:
    NetworkController controller;

public:
    void displayMenu();
    void execute();
    
private:
    void pause();
};

#endif
