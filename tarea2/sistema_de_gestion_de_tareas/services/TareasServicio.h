#ifndef TAREAS_SERVICIO_H
#define TAREAS_SERVICIO_H

#include "../domain/Tarea.h"
#include "../repository/ListaOrdenadaRepositorio.h"
#include "ValidadorTareaServicio.h"
#include <cstdio>

// Estructura para informacion de tarea
struct InfoTarea {
    char nombre[200];
    int prioridad;
    char estado[20];
    int id;
};

// Servicio: Gestor de tareas con prioridad
class TareasServicio {
private:
    ListaOrdenadaRepositorio<Tarea> listaTareas;
    ValidadorTareaServicio validador;
    int contadorIds;
    
public:
    TareasServicio() : contadorIds(0) {}
    
    // a) Insertar tarea ordenada por prioridad (descendente)
    bool agregarTarea(const char* nombre, int prioridad) {
        if (!validador.esTareaValida(nombre, prioridad)) {
            return false;
        }
        
        contadorIds++;
        Tarea nuevaTarea(nombre, prioridad, contadorIds);
        
        return listaTareas.insertarOrdenado(nuevaTarea, prioridad);
    }
    
    // b) Obtener todas las tareas pendientes
    void obtenerTareasPendientes(InfoTarea tareas[], int& cantidad) const {
        cantidad = 0;
        
        listaTareas.recorrer([&tareas, &cantidad](const Tarea& tarea) {
            if (tarea.esPendiente()) {
                InfoTarea& info = tareas[cantidad];
                
                strcpy(info.nombre, tarea.obtenerNombre());
                info.prioridad = tarea.obtenerPrioridad();
                strcpy(info.estado, tarea.obtenerEstadoTexto());
                info.id = tarea.obtenerId();
                
                cantidad++;
            }
        });
    }
    
    // Obtener todas las tareas (pendientes y completadas)
    void obtenerTodasTareas(InfoTarea tareas[], int& cantidad) const {
        cantidad = 0;
        
        listaTareas.recorrer([&tareas, &cantidad](const Tarea& tarea) {
            InfoTarea& info = tareas[cantidad];
            
            strcpy(info.nombre, tarea.obtenerNombre());
            info.prioridad = tarea.obtenerPrioridad();
            strcpy(info.estado, tarea.obtenerEstadoTexto());
            info.id = tarea.obtenerId();
            
            cantidad++;
        });
    }
    
    // Marcar tarea como completada por ID
    bool marcarCompletada(int id) {
        bool encontrada = false;
        
        Nodo<Tarea>* actual = listaTareas.obtenerCabeza();
        
        while (actual != nullptr) {
            if (actual->dato.obtenerId() == id) {
                actual->dato.marcarCompletada();
                encontrada = true;
                break;
            }
            actual = actual->siguiente;
        }
        
        return encontrada;
    }
    
    // c) Eliminar tareas completadas
    int eliminarCompletadas() {
        int cantidadAntes = listaTareas.obtenerTamanio();
        
        listaTareas.eliminarSi([](const Tarea& tarea) {
            return tarea.esCompletada();
        });
        
        int cantidadDespues = listaTareas.obtenerTamanio();
        return cantidadAntes - cantidadDespues;
    }
    
    int obtenerCantidadTotal() const {
        return listaTareas.obtenerTamanio();
    }
    
    int obtenerCantidadPendientes() const {
        int contador = 0;
        
        listaTareas.recorrer([&contador](const Tarea& tarea) {
            if (tarea.esPendiente()) {
                contador++;
            }
        });
        
        return contador;
    }
    
    int obtenerCantidadCompletadas() const {
        int contador = 0;
        
        listaTareas.recorrer([&contador](const Tarea& tarea) {
            if (tarea.esCompletada()) {
                contador++;
            }
        });
        
        return contador;
    }
    
    void limpiarTareas() {
        listaTareas.limpiar();
    }
    
    void reiniciarSistema() {
        listaTareas.limpiar();
        contadorIds = 0;
    }
};

#endif