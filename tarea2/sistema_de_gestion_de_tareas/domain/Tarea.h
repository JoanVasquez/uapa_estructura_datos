#ifndef TAREA_H
#define TAREA_H

#include <cstring>

// Enumeracion para estado de tarea
enum EstadoTarea {
    PENDIENTE = 0,
    COMPLETADA = 1
};

// Entidad: Tarea - Representa una tarea con prioridad
class Tarea {
private:
    static const int MAX_NOMBRE = 200;
    char nombre[MAX_NOMBRE];
    int nivelPrioridad;
    EstadoTarea estado;
    int id;
    
public:
    Tarea() : nivelPrioridad(0), estado(PENDIENTE), id(0) {
        nombre[0] = '\0';
    }
    
    Tarea(const char* nombreParam, int prioridad, int idParam) {
        establecerNombre(nombreParam);
        nivelPrioridad = prioridad;
        estado = PENDIENTE;
        id = idParam;
    }
    
    void establecerNombre(const char* nombreParam) {
        if (nombreParam != nullptr) {
            strncpy(nombre, nombreParam, MAX_NOMBRE - 1);
            nombre[MAX_NOMBRE - 1] = '\0';
        }
    }
    
    void establecerPrioridad(int prioridad) {
        nivelPrioridad = prioridad;
    }
    
    void establecerEstado(EstadoTarea nuevoEstado) {
        estado = nuevoEstado;
    }
    
    void establecerId(int idParam) {
        id = idParam;
    }
    
    const char* obtenerNombre() const {
        return nombre;
    }
    
    int obtenerPrioridad() const {
        return nivelPrioridad;
    }
    
    EstadoTarea obtenerEstado() const {
        return estado;
    }
    
    int obtenerId() const {
        return id;
    }
    
    bool esPendiente() const {
        return estado == PENDIENTE;
    }
    
    bool esCompletada() const {
        return estado == COMPLETADA;
    }
    
    void marcarCompletada() {
        estado = COMPLETADA;
    }
    
    const char* obtenerEstadoTexto() const {
        return (estado == PENDIENTE) ? "PENDIENTE" : "COMPLETADA";
    }
    
    bool esValida() const {
        return nombre[0] != '\0';
    }
};

#endif