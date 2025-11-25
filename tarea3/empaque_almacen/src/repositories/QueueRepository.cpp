#include "repositories/QueueRepository.h"
#include <iostream>

QueueRepository::QueueRepository() : front(0), rear(-1), count(0) {
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        queue[i] = nullptr;
    }
}

QueueRepository::~QueueRepository() {
    clear();
}

bool QueueRepository::isFull() const {
    return count >= MAX_QUEUE_SIZE;
}

void QueueRepository::shiftElements() {
    // Si el frente no está en 0, shift elementos para optimizar espacio
    if (front > 0 && count > 0) {
        for (int i = 0; i < count; i++) {
            queue[i] = queue[front + i];
            queue[front + i] = nullptr;
        }
        rear = count - 1;
        front = 0;
    }
}

bool QueueRepository::enqueue(Box* box) {
    if (isFull() || box == nullptr) {
        return false;
    }
    
    // Si estamos al final del array y hay espacio al inicio, hacer shift
    if (rear == MAX_QUEUE_SIZE - 1 && front > 0) {
        shiftElements();
    }
    
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = box;
    count++;
    return true;
}

Box* QueueRepository::dequeue() {
    if (isEmpty()) {
        return nullptr;
    }
    
    Box* box = queue[front];
    queue[front] = nullptr;
    front = (front + 1) % MAX_QUEUE_SIZE;
    count--;
    
    // Si la cola queda vacía, resetear índices
    if (isEmpty()) {
        front = 0;
        rear = -1;
    }
    
    return box;
}

Box* QueueRepository::peek() const {
    if (isEmpty()) {
        return nullptr;
    }
    return queue[front];
}

bool QueueRepository::isEmpty() const {
    return count == 0;
}

int QueueRepository::getCount() const {
    return count;
}

Box** QueueRepository::getAllBoxes(int& boxCount) const {
    boxCount = count;
    Box** boxes = new Box*[count];
    
    for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX_QUEUE_SIZE;
        boxes[i] = queue[index];
    }
    
    return boxes;
}

void QueueRepository::clear() {
    while (!isEmpty()) {
        Box* box = dequeue();
        delete box;
    }
}
