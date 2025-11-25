#ifndef QUEUEREPOSITORY_H
#define QUEUEREPOSITORY_H

#include "entities/Box.h"

class QueueRepository {
private:
    static const int MAX_QUEUE_SIZE = 100;
    Box* queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;

    bool isFull() const;
    void shiftElements();

public:
    QueueRepository();
    ~QueueRepository();
    
    bool enqueue(Box* box);
    Box* dequeue();
    Box* peek() const;
    bool isEmpty() const;
    int getCount() const;
    Box** getAllBoxes(int& boxCount) const;
    void clear();
};

#endif
