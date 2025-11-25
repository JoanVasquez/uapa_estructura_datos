#ifndef PACKINGSERVICE_H
#define PACKINGSERVICE_H

#include "repositories/QueueRepository.h"
#include <string>

class PackingService {
private:
    QueueRepository* repository;

public:
    PackingService(QueueRepository* repo);
    ~PackingService();
    
    bool addBox(const std::string& description);
    bool processBox(std::string& resultMessage);
    std::string viewQueue() const;
    int getQueueSize() const;
    bool isQueueEmpty() const;
    std::string getQueueStatus() const;
};

#endif
