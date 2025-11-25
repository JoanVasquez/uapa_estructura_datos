#ifndef NAVIGATIONSERVICE_H
#define NAVIGATIONSERVICE_H

#include "repositories/HistoryRepository.h"
#include <string>

class NavigationService {
private:
    HistoryRepository* repository;

public:
    NavigationService(HistoryRepository* repo);
    ~NavigationService();
    
    bool visit(const std::string& url);
    bool back();
    bool forward();
    std::string getCurrentPageInfo() const;
    std::string getBackHistoryInfo() const;
    std::string getForwardHistoryInfo() const;
    std::string getFullStatus() const;
    bool hasCurrentPage() const;
};

#endif
