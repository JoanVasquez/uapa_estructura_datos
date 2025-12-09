#ifndef RANKINGCONTROLLER_H
#define RANKINGCONTROLLER_H

#include "../services/RankingService.h"

class RankingController {
private:
    RankingService service;

public:
    void executeOption(int option);
};

#endif
