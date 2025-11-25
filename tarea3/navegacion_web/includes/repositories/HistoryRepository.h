#ifndef HISTORYREPOSITORY_H
#define HISTORYREPOSITORY_H

#include "entities/WebPage.h"
#include <string>

class HistoryRepository {
private:
    static const int MAX_HISTORY = 100;
    WebPage* backHistory[MAX_HISTORY];
    WebPage* forwardHistory[MAX_HISTORY];
    int backTop;
    int forwardTop;
    WebPage* currentPage;

    bool isBackFull() const;
    bool isForwardFull() const;
    void clearForwardHistory();

public:
    HistoryRepository();
    ~HistoryRepository();
    
    bool visitPage(const std::string& url);
    bool goBack();
    bool goForward();
    WebPage* getCurrentPage() const;
    WebPage** getBackHistory(int& count) const;
    WebPage** getForwardHistory(int& count) const;
    void clearAll();
};

#endif
