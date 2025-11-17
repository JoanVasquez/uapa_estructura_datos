#ifndef LISTA_DOBLE_REPOSITORIO_H
#define LISTA_DOBLE_REPOSITORIO_H

#include "../domain/NodoDoble.h"

template<typename T>
class ListaDobleRepositorio {
private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola;
    int tamanio;
    
public:
    ListaDobleRepositorio() : cabeza(nullptr), cola(nullptr), tamanio(0) {}
    
    ~ListaDobleRepositorio() {
        limpiar();
    }
    
    bool estaVacia() const {
        return cabeza == nullptr;
    }
    
    int obtenerTamanio() const {
        return tamanio;
    }
    
    // a) Insertar al final de la lista
    bool insertarAlFinal(const T& dato) {
        NodoDoble<T>* nuevoNodo = new NodoDoble<T>(dato);
        
        if (nuevoNodo == nullptr) {
            return false;
        }
        
        if (estaVacia()) {
            cabeza = cola = nuevoNodo;
        } else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
        
        tamanio++;
        return true;
    }
    
    // Buscar pagina por URL
    T* buscarPorUrl(const char* url) {
        NodoDoble<T>* actual = cabeza;
        
        while (actual != nullptr) {
            if (actual->dato.coincideUrl(url)) {
                return &(actual->dato);
            }
            actual = actual->siguiente;
        }
        
        return nullptr;
    }
    
    // Eliminar nodo por URL
    bool eliminarPorUrl(const char* url) {
        if (estaVacia()) {
            return false;
        }
        
        NodoDoble<T>* actual = cabeza;
        bool eliminado = false;
        
        while (actual != nullptr) {
            if (actual->dato.coincideUrl(url)) {
                NodoDoble<T>* aEliminar = actual;
                
                if (aEliminar == cabeza) {
                    cabeza = cabeza->siguiente;
                    if (cabeza != nullptr) {
                        cabeza->anterior = nullptr;
                    }
                } else if (aEliminar == cola) {
                    cola = cola->anterior;
                    if (cola != nullptr) {
                        cola->siguiente = nullptr;
                    }
                } else {
                    aEliminar->anterior->siguiente = aEliminar->siguiente;
                    aEliminar->siguiente->anterior = aEliminar->anterior;
                }
                
                actual = actual->siguiente;
                delete aEliminar;
                tamanio--;
                eliminado = true;
            } else {
                actual = actual->siguiente;
            }
        }
        
        // Si la lista queda vacia
        if (tamanio == 0) {
            cabeza = cola = nullptr;
        }
        
        return eliminado;
    }
    
    // Recorrer desde el inicio al final
    template<typename Funcion>
    void recorrerAdelante(Funcion func) const {
        NodoDoble<T>* actual = cabeza;
        while (actual != nullptr) {
            func(actual->dato);
            actual = actual->siguiente;
        }
    }
    
    // d) Recorrer desde el final al inicio (orden cronologico inverso)
    template<typename Funcion>
    void recorrerAtras(Funcion func) const {
        NodoDoble<T>* actual = cola;
        while (actual != nullptr) {
            func(actual->dato);
            actual = actual->anterior;
        }
    }
    
    // Obtener cabeza y cola para navegacion
    NodoDoble<T>* obtenerCabeza() const {
        return cabeza;
    }
    
    NodoDoble<T>* obtenerCola() const {
        return cola;
    }
    
    // Limpiar toda la lista
    void limpiar() {
        NodoDoble<T>* actual = cabeza;
        while (actual != nullptr) {
            NodoDoble<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        cabeza = cola = nullptr;
        tamanio = 0;
    }
};

#endif