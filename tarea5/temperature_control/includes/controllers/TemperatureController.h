#ifndef TEMPERATURECONTROLLER_H
#define TEMPERATURECONTROLLER_H

#include "../services/TemperatureService.h"

class TemperatureController {
private:
    TemperatureService service;

public:
    void executeOption(int option);
};

#endif
