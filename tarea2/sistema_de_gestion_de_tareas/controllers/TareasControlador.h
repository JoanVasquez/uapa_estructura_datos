#ifndef TAREAS_CONTROLADOR_H
#define TAREAS_CONTROLADOR_H

#include "../services/TareasServicio.h"
#include "../services/MedidorTiempoServicio.h"
#include <cstring>
#include <cstdio>

// Estructura de respuesta
struct RespuestaTareas {
    bool exito;
    char mensaje[300];
    double tiempoEjecucion;
    int datos;
};

class TareasControlador {
private:
    TareasServicio servicio;
    MedidorTiempoServicio medidor;
    
public:
    // a) Agregar tarea ordenada por prioridad
    RespuestaTareas procesarAgregar(const char* nombre, int prioridad) {
        RespuestaTareas respuesta;
        
        medidor.iniciar();
        bool exito = servicio.agregarTarea(nombre, prioridad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = exito;
        
        if (exito) {
            sprintf(respuesta.mensaje, 
                    "Tarea agregada: '%s' con prioridad %d", 
                    nombre, prioridad);
            respuesta.datos = prioridad;
        } else {
            sprintf(respuesta.mensaje, "Error: Datos invalidos para la tarea.");
            respuesta.datos = 0;
        }
        
        return respuesta;
    }
    
    // b) Mostrar tareas pendientes
    RespuestaTareas procesarMostrarPendientes(InfoTarea tareas[], int& cantidad) {
        RespuestaTareas respuesta;
        
        medidor.iniciar();
        servicio.obtenerTareasPendientes(tareas, cantidad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = cantidad;
        
        if (cantidad == 0) {
            sprintf(respuesta.mensaje, "No hay tareas pendientes.");
        } else {
            sprintf(respuesta.mensaje, "Tareas pendientes: %d", cantidad);
        }
        
        return respuesta;
    }
    
    // Mostrar todas las tareas
    RespuestaTareas procesarMostrarTodas(InfoTarea tareas[], int& cantidad) {
        RespuestaTareas respuesta;
        
        medidor.iniciar();
        servicio.obtenerTodasTareas(tareas, cantidad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = cantidad;
        
        if (cantidad == 0) {
            sprintf(respuesta.mensaje, "No hay tareas registradas.");
        } else {
            sprintf(respuesta.mensaje, "Total de tareas: %d", cantidad);
        }
        
        return respuesta;
    }
    
    // Marcar tarea como completada
    RespuestaTareas procesarCompletar(int id) {
        RespuestaTareas respuesta;
        
        medidor.iniciar();
        bool exito = servicio.marcarCompletada(id);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = exito;
        respuesta.datos = id;
        
        if (exito) {
            sprintf(respuesta.mensaje, "Tarea #%d marcada como COMPLETADA.", id);
        } else {
            sprintf(respuesta.mensaje, "Error: Tarea #%d no encontrada.", id);
        }
        
        return respuesta;
    }
    
    // c) Eliminar tareas completadas
    RespuestaTareas procesarEliminarCompletadas() {
        RespuestaTareas respuesta;
        
        medidor.iniciar();
        int eliminadas = servicio.eliminarCompletadas();
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = eliminadas;
        
        if (eliminadas == 0) {
            sprintf(respuesta.mensaje, "No habia tareas completadas para eliminar.");
        } else if (eliminadas == 1) {
            sprintf(respuesta.mensaje, "1 tarea completada eliminada.");
        } else {
            sprintf(respuesta.mensaje, "%d tareas completadas eliminadas.", eliminadas);
        }
        
        return respuesta;
    }
    
    RespuestaTareas procesarLimpiar() {
        RespuestaTareas respuesta;
        
        medidor.iniciar();
        servicio.limpiarTareas();
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = 0;
        sprintf(respuesta.mensaje, "Todas las tareas han sido eliminadas.");
        
        return respuesta;
    }
    
    RespuestaTareas procesarReiniciar() {
        RespuestaTareas respuesta;
        
        medidor.iniciar();
        servicio.reiniciarSistema();
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = 0;
        sprintf(respuesta.mensaje, "Sistema reiniciado completamente.");
        
        return respuesta;
    }
    
    // Estadisticas
    int obtenerCantidadTotal() const {
        return servicio.obtenerCantidadTotal();
    }
    
    int obtenerCantidadPendientes() const {
        return servicio.obtenerCantidadPendientes();
    }
    
    int obtenerCantidadCompletadas() const {
        return servicio.obtenerCantidadCompletadas();
    }
    
    double obtenerTiempoTotalEjecucion() const {
        return medidor.obtenerTiempoTotal();
    }
};

#endif