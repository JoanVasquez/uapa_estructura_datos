#ifndef INVENTARIO_CONTROLADOR_H
#define INVENTARIO_CONTROLADOR_H

#include "../services/InventarioServicio.h"
#include "../services/MedidorTiempoServicio.h"
#include <cstring>
#include <cstdio>

// Estructura de respuesta
struct RespuestaInventario {
    bool exito;
    char mensaje[300];
    double tiempoEjecucion;
    int datos;
};

class InventarioControlador {
private:
    InventarioServicio servicio;
    MedidorTiempoServicio medidor;
    
public:
    // a) Agregar producto
    RespuestaInventario procesarAgregar(int codigo, const char* nombre, int cantidad) {
        RespuestaInventario respuesta;
        
        medidor.iniciar();
        bool exito = servicio.agregarProducto(codigo, nombre, cantidad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = exito;
        
        if (exito) {
            sprintf(respuesta.mensaje, 
                    "Producto agregado: '%s' (Codigo: %d, Cantidad: %d)", 
                    nombre, codigo, cantidad);
            respuesta.datos = codigo;
        } else {
            sprintf(respuesta.mensaje, "Error: Datos invalidos o codigo duplicado.");
            respuesta.datos = 0;
        }
        
        return respuesta;
    }
    
    // b) Mostrar productos con stock bajo
    RespuestaInventario procesarMostrarStockBajo(InfoProducto productos[], int& cantidad) {
        RespuestaInventario respuesta;
        
        medidor.iniciar();
        servicio.obtenerProductosStockBajo(productos, cantidad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = cantidad;
        
        if (cantidad == 0) {
            sprintf(respuesta.mensaje, "No hay productos con stock bajo (< 5 unidades).");
        } else {
            sprintf(respuesta.mensaje, "Productos con stock bajo: %d", cantidad);
        }
        
        return respuesta;
    }
    
    // Mostrar todos los productos
    RespuestaInventario procesarMostrarTodos(InfoProducto productos[], int& cantidad) {
        RespuestaInventario respuesta;
        
        medidor.iniciar();
        servicio.obtenerTodosProductos(productos, cantidad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = cantidad;
        
        if (cantidad == 0) {
            sprintf(respuesta.mensaje, "No hay productos en el inventario.");
        } else {
            sprintf(respuesta.mensaje, "Total de productos: %d", cantidad);
        }
        
        return respuesta;
    }
    
    // c) Actualizar stock de producto
    RespuestaInventario procesarActualizarStock(int codigo, int nuevaCantidad) {
        RespuestaInventario respuesta;
        
        medidor.iniciar();
        bool exito = servicio.actualizarStock(codigo, nuevaCantidad);
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = exito;
        respuesta.datos = codigo;
        
        if (exito) {
            sprintf(respuesta.mensaje, "Stock del producto #%d actualizado a %d unidades.", codigo, nuevaCantidad);
        } else {
            sprintf(respuesta.mensaje, "Error: Producto #%d no encontrado o cantidad invalida.", codigo);
        }
        
        return respuesta;
    }
    
    RespuestaInventario procesarLimpiar() {
        RespuestaInventario respuesta;
        
        medidor.iniciar();
        servicio.limpiarInventario();
        respuesta.tiempoEjecucion = medidor.detener();
        
        respuesta.exito = true;
        respuesta.datos = 0;
        sprintf(respuesta.mensaje, "Todo el inventario ha sido eliminado.");
        
        return respuesta;
    }
    
    RespuestaInventario procesarReiniciar() {
        RespuestaInventario respuesta;
        
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
    
    int obtenerCantidadStockBajo() const {
        return servicio.obtenerCantidadStockBajo();
    }
    
    double obtenerTiempoTotalEjecucion() const {
        return medidor.obtenerTiempoTotal();
    }
};

#endif