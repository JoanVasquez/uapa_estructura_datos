#ifndef STACK_H
#define STACK_H

class Stack {
private:
    static const int MAX_SIZE = 100;
    double data[MAX_SIZE];
    int top;

public:
    Stack();
    bool push(double value);
    bool pop(double& value);
    bool peek(double& value) const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    void clear();
};

#endif
