#ifndef PRIMETREEVIEW_H
#define PRIMETREEVIEW_H

#include "../controllers/PrimeTreeController.h"

class PrimeTreeView {
private:
    PrimeTreeController controller;

public:
    void displayMenu();
    void execute();
    
private:
    void pause();
};

#endif
