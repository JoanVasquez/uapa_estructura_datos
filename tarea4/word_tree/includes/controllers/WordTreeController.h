#ifndef WORDTREECONTROLLER_H
#define WORDTREECONTROLLER_H

#include "../services/WordTreeService.h"

class WordTreeController {
private:
    WordTreeService service;

public:
    void executeOption(int option);
};

#endif
