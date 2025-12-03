#ifndef PRIMETREECONTROLLER_H
#define PRIMETREECONTROLLER_H

#include "../services/PrimeTreeService.h"

class PrimeTreeController {
private:
    PrimeTreeService service;

public:
    void executeOption(int option);
};

#endif
