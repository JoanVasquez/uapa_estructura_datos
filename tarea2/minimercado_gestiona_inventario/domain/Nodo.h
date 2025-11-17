#ifndef NODO_H
#define NODO_H

// Nodo para lista simple
template<typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    
    Nodo() : siguiente(nullptr) {}
    
    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
};

#endif