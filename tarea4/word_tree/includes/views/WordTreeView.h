#ifndef WORDTREEVIEW_H
#define WORDTREEVIEW_H

#include "../controllers/WordTreeController.h"

class WordTreeView {
private:
    WordTreeController controller;

public:
    void displayMenu();
    void execute();
    
private:
    void pause();
};

#endif
