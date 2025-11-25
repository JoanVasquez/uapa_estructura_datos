#include "entities/Stack.h"

Stack::Stack() : top(-1) {}

bool Stack::push(double value) {
    if (isFull()) {
        return false;
    }
    data[++top] = value;
    return true;
}

bool Stack::pop(double& value) {
    if (isEmpty()) {
        return false;
    }
    value = data[top--];
    return true;
}

bool Stack::peek(double& value) const {
    if (isEmpty()) {
        return false;
    }
    value = data[top];
    return true;
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top >= MAX_SIZE - 1;
}

int Stack::getSize() const {
    return top + 1;
}

void Stack::clear() {
    top = -1;
}
