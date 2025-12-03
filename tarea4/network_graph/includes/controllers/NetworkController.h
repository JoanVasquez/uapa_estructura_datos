#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H

#include "../services/NetworkService.h"

class NetworkController {
private:
    NetworkService service;

public:
    void executeOption(int option);
};

#endif
