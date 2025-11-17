#ifndef HISTORIAL_CONTROLADOR_H
#define HISTORIAL_CONTROLADOR_H

#include "../services/HistorialServicio.h"
#include "../services/MedidorTiempoServicio.h"
#include <cstring>
#include <cstdio>

struct RespuestaHistorial {
    bool exito;
    char mensaje[300];
    double tiempoEjecucion;
    int datos;
};

class HistorialControlador {
private:
    HistorialServicio servicio;
    MedidorTiempoServicio medidor;
    
public:
    // a) Insertar visita
    RespuestaHistorial procesarAgregar(const char* url, const char* fechaHora) {
        RespuestaHistorial respuesta;
        
        medidor.iniciar();
        bool exito = servicio.agregarPagina(url, fechaHora);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = exito;
        
        if (exito) {
            sprintf(respuesta.mensaje, 
                    "Pagina agregada al historial: '%s'", url);
            respuesta.datos = servicio.obtenerCantidadTotal();
        } else {
            sprintf(respuesta.mensaje, "Error: URL o fecha invalidos.");
            respuesta.datos = 0;
        }
        
        return respuesta;
    }
    
    // b) Navegacion
    RespuestaHistorial procesarNavegarAtras() {
        RespuestaHistorial respuesta;
        
        medidor.iniciar();
        bool exito = servicio.navegarAtras();
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = exito;
        
        const Pagina* actual = servicio.obtenerPaginaActual();
        if (exito && actual != nullptr) {
            sprintf(respuesta.mensaje, "Navegando ATRAS: %s", actual->obtenerUrl());
            respuesta.datos = 1;
        } else {
            sprintf(respuesta.mensaje, "No hay paginas anteriores.");
            respuesta.datos = 0;
        }
        
        return respuesta;
    }
    
    RespuestaHistorial procesarNavegarAdelante() {
        RespuestaHistorial respuesta;
        
        medidor.iniciar();
        bool exito = servicio.navegarAdelante();
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = exito;
        
        const Pagina* actual = servicio.obtenerPaginaActual();
        if (exito && actual != nullptr) {
            sprintf(respuesta.mensaje, "Navegando ADELANTE: %s", actual->obtenerUrl());
            respuesta.datos = 1;
        } else {
            sprintf(respuesta.mensaje, "No hay paginas siguientes.");
            respuesta.datos = 0;
        }
        
        return respuesta;
    }
    
    // c) Eliminar URL
    RespuestaHistorial procesarEliminarUrl(const char* url) {
        RespuestaHistorial respuesta;
        
        medidor.iniciar();
        int eliminadas = servicio.eliminarUrl(url);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = (eliminadas > 0);
        respuesta.datos = eliminadas;
        
        if (eliminadas > 0) {
            sprintf(respuesta.mensaje, "Se eliminaron %d ocurrencias de '%s'", eliminadas, url);
        } else {
            sprintf(respuesta.mensaje, "No se encontro la URL '%s' en el historial", url);
        }
        
        return respuesta;
    }
    
    // d) Mostrar historial reverso
    RespuestaHistorial procesarMostrarReverso(InfoPagina paginas[], int& cantidad) {
        RespuestaHistorial respuesta;
        
        medidor.iniciar();
        servicio.obtenerHistorialReverso(paginas, cantidad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = cantidad;
        
        if (cantidad == 0) {
            sprintf(respuesta.mensaje, "El historial esta vacio.");
        } else {
            sprintf(respuesta.mensaje, "Historial (ultima a primera visita): %d paginas", cantidad);
        }
        
        return respuesta;
    }
    
    // Mostrar pagina actual
    RespuestaHistorial obtenerPaginaActual() {
        RespuestaHistorial respuesta;
        
        medidor.iniciar();
        const Pagina* actual = servicio.obtenerPaginaActual();
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = (actual != nullptr);
        
        if (actual != nullptr) {
            sprintf(respuesta.mensaje, "Pagina actual: %s - %s", 
                    actual->obtenerUrl(), actual->obtenerFechaHora());
            respuesta.datos = 1;
        } else {
            sprintf(respuesta.mensaje, "No hay pagina actual.");
            respuesta.datos = 0;
        }
        
        return respuesta;
    }
    
    // Estadisticas
    int obtenerCantidadTotal() const {
        return servicio.obtenerCantidadTotal();
    }
    
    double obtenerTiempoTotalEjecucion() const {
        return medidor.obtenerTiempoTotal();
    }
};

#endif