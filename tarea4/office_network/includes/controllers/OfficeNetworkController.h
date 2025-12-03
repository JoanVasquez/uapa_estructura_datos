#ifndef OFFICENETWORKCONTROLLER_H
#define OFFICENETWORKCONTROLLER_H

#include "../services/OfficeNetworkService.h"

class OfficeNetworkController {
private:
    OfficeNetworkService service;

public:
    void executeOption(int option);
};

#endif
