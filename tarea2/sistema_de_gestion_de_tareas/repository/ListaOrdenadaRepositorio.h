#ifndef LISTA_ORDENADA_REPOSITORIO_H
#define LISTA_ORDENADA_REPOSITORIO_H

#include "../domain/Nodo.h"

// Repositorio: Lista ordenada por prioridad (descendente)
template<typename T>
class ListaOrdenadaRepositorio {
private:
    Nodo<T>* cabeza;
    int tamanio;
    
public:
    ListaOrdenadaRepositorio() : cabeza(nullptr), tamanio(0) {}
    
    ~ListaOrdenadaRepositorio() {
        limpiar();
    }
    
    bool estaVacia() const {
        return cabeza == nullptr;
    }
    
    int obtenerTamanio() const {
        return tamanio;
    }
    
    // Insertar ordenado por prioridad (descendente: mayor a menor)
    bool insertarOrdenado(const T& dato, int prioridad) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        
        if (nuevoNodo == nullptr) {
            return false;
        }
        
        // Lista vacia o prioridad mayor que cabeza
        if (cabeza == nullptr || prioridad > cabeza->dato.obtenerPrioridad()) {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        } else {
            // Buscar posicion correcta
            Nodo<T>* actual = cabeza;
            
            while (actual->siguiente != nullptr && 
                   actual->siguiente->dato.obtenerPrioridad() >= prioridad) {
                actual = actual->siguiente;
            }
            
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        }
        
        tamanio++;
        return true;
    }
    
    // Eliminar nodo que cumpla condicion
    template<typename Predicado>
    bool eliminarSi(Predicado condicion) {
        if (estaVacia()) {
            return false;
        }
        
        bool eliminado = false;
        
        // Eliminar desde la cabeza si cumple condicion
        while (cabeza != nullptr && condicion(cabeza->dato)) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            tamanio--;
            eliminado = true;
        }
        
        // Eliminar del resto de la lista
        if (cabeza != nullptr) {
            Nodo<T>* actual = cabeza;
            
            while (actual->siguiente != nullptr) {
                if (condicion(actual->siguiente->dato)) {
                    Nodo<T>* temp = actual->siguiente;
                    actual->siguiente = temp->siguiente;
                    delete temp;
                    tamanio--;
                    eliminado = true;
                } else {
                    actual = actual->siguiente;
                }
            }
        }
        
        return eliminado;
    }
    
    // Recorrer lista aplicando funcion
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