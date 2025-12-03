#ifndef OFFICENETWORKVIEW_H
#define OFFICENETWORKVIEW_H

#include "../controllers/OfficeNetworkController.h"

class OfficeNetworkView {
private:
    OfficeNetworkController controller;

public:
    void displayMenu();
    void execute();
    
private:
    void pause();
};

#endif
