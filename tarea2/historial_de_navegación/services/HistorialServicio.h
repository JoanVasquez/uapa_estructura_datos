#ifndef HISTORIAL_SERVICIO_H
#define HISTORIAL_SERVICIO_H

#include "../domain/Pagina.h"
#include "../repository/ListaDobleRepositorio.h"
#include "ValidadorPaginaServicio.h"
#include <cstdio>

struct InfoPagina {
    char url[200];
    char fechaHora[20];
};

class HistorialServicio {
private:
    ListaDobleRepositorio<Pagina> listaHistorial;
    ValidadorPaginaServicio validador;
    NodoDoble<Pagina>* paginaActual;
    
public:
    HistorialServicio() : paginaActual(nullptr) {}
    
    // a) Insertar nueva visita al final
    bool agregarPagina(const char* url, const char* fechaHora) {
        if (!validador.esPaginaValida(url, fechaHora)) {
            return false;
        }
        
        Pagina nuevaPagina(url, fechaHora);
        bool exito = listaHistorial.insertarAlFinal(nuevaPagina);
        
        if (exito) {
            paginaActual = listaHistorial.obtenerCola();
        }
        
        return exito;
    }
    
    // b) Navegacion hacia adelante y atras
    bool navegarAtras() {
        if (paginaActual == nullptr || paginaActual->anterior == nullptr) {
            return false;
        }
        
        paginaActual = paginaActual->anterior;
        return true;
    }
    
    bool navegarAdelante() {
        if (paginaActual == nullptr || paginaActual->siguiente == nullptr) {
            return false;
        }
        
        paginaActual = paginaActual->siguiente;
        return true;
    }
    
    // Obtener pagina actual
    const Pagina* obtenerPaginaActual() const {
        return (paginaActual != nullptr) ? &(paginaActual->dato) : nullptr;
    }
    
    // c) Eliminar URL especifica
    int eliminarUrl(const char* url) {
        if (!validador.esUrlValida(url)) {
            return 0;
        }
        
        int eliminadasAntes = listaHistorial.obtenerTamanio();
        listaHistorial.eliminarPorUrl(url);  // Eliminada la variable 'exito' no usada
        int eliminadasDespues = listaHistorial.obtenerTamanio();
        
        // Actualizar pagina actual si fue eliminada
        if (paginaActual != nullptr) {
            Pagina* pagina = listaHistorial.buscarPorUrl(paginaActual->dato.obtenerUrl());
            if (pagina == nullptr) {
                paginaActual = listaHistorial.obtenerCola();
            }
        }
        
        return eliminadasAntes - eliminadasDespues;
    }
    
    // d) Mostrar historial en orden cronologico inverso
    void obtenerHistorialReverso(InfoPagina paginas[], int& cantidad) const {
        cantidad = 0;
        
        listaHistorial.recorrerAtras([&paginas, &cantidad](const Pagina& pagina) {
            InfoPagina& info = paginas[cantidad];
            strcpy(info.url, pagina.obtenerUrl());
            strcpy(info.fechaHora, pagina.obtenerFechaHora());
            cantidad++;
        });
    }
    
    // Mostrar historial completo
    void obtenerHistorialCompleto(InfoPagina paginas[], int& cantidad) const {
        cantidad = 0;
        
        listaHistorial.recorrerAdelante([&paginas, &cantidad](const Pagina& pagina) {
            InfoPagina& info = paginas[cantidad];
            strcpy(info.url, pagina.obtenerUrl());
            strcpy(info.fechaHora, pagina.obtenerFechaHora());
            cantidad++;
        });
    }
    
    int obtenerCantidadTotal() const {
        return listaHistorial.obtenerTamanio();
    }
    
    void limpiarHistorial() {
        listaHistorial.limpiar();
        paginaActual = nullptr;
    }
    
    void reiniciarSistema() {
        listaHistorial.limpiar();
        paginaActual = nullptr;
    }
};

#endif