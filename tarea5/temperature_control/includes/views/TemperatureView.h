#ifndef TEMPERATUREVIEW_H
#define TEMPERATUREVIEW_H

#include "../controllers/TemperatureController.h"

class TemperatureView {
private:
    TemperatureController controller;

public:
    void displayMenu();
    void execute();
    
private:
    void pause();
};

#endif
