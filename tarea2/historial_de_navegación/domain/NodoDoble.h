#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H

template<typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble<T>* anterior;
    NodoDoble<T>* siguiente;
    
    NodoDoble() : anterior(nullptr), siguiente(nullptr) {}
    
    NodoDoble(const T& valor) : dato(valor), anterior(nullptr), siguiente(nullptr) {}
};

#endif