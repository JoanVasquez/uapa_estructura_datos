#ifndef RANKINGVIEW_H
#define RANKINGVIEW_H

#include "../controllers/RankingController.h"

class RankingView {
private:
    RankingController controller;

public:
    void displayMenu();
    void execute();
    
private:
    void pause();
};

#endif
