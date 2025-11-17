#ifndef LISTA_SIMPLE_REPOSITORIO_H
#define LISTA_SIMPLE_REPOSITORIO_H

#include "../domain/Nodo.h"

// Repositorio: Lista simple para productos
template<typename T>
class ListaSimpleRepositorio {
private:
    Nodo<T>* cabeza;
    int tamanio;
    
public:
    ListaSimpleRepositorio() : cabeza(nullptr), tamanio(0) {}
    
    ~ListaSimpleRepositorio() {
        limpiar();
    }
    
    bool estaVacia() const {
        return cabeza == nullptr;
    }
    
    int obtenerTamanio() const {
        return tamanio;
    }
    
    // Insertar al final de la lista
    bool insertar(const T& dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        
        if (nuevoNodo == nullptr) {
            return false;
        }
        
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
        
        tamanio++;
        return true;
    }
    
    // Buscar producto por código
    T* buscarPorCodigo(int codigo) {
        Nodo<T>* actual = cabeza;
        
        while (actual != nullptr) {
            if (actual->dato.obtenerCodigo() == codigo) {
                return &(actual->dato);
            }
            actual = actual->siguiente;
        }
        
        return nullptr;
    }
    
    // Recorrer lista aplicando función
    template<typename Funcion>
    void recorrer(Funcion func) const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            func(actual->dato);
            actual = actual->siguiente;
        }
    }
    
    // Obtener cabeza
    Nodo<T>* obtenerCabeza() const {
        return cabeza;
    }
    
    // Limpiar toda la lista
    void limpiar() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        cabeza = nullptr;
        tamanio = 0;
    }
};

#endif