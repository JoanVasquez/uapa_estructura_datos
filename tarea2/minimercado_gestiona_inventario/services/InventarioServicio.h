#ifndef INVENTARIO_SERVICIO_H
#define INVENTARIO_SERVICIO_H

#include "../domain/Producto.h"
#include "../repository/ListaSimpleRepositorio.h"
#include "ValidadorProductoServicio.h"
#include <cstdio>

struct InfoProducto {
    char nombre[100];
    int codigo;
    int cantidad;
};

class InventarioServicio {
private:
    ListaSimpleRepositorio<Producto> listaProductos;
    ValidadorProductoServicio validador;
    
public:
    InventarioServicio() {}
    
    bool agregarProducto(int codigo, const char* nombre, int cantidad) {
        if (!validador.esProductoValido(codigo, nombre, cantidad)) {
            return false;
        }
        
        if (listaProductos.buscarPorCodigo(codigo) != nullptr) {
            return false;
        }
        
        Producto nuevoProducto(codigo, nombre, cantidad);
        return listaProductos.insertar(nuevoProducto);
    }
    
    void obtenerProductosStockBajo(InfoProducto productos[], int& cantidad) const {
        cantidad = 0;
        
        listaProductos.recorrer([&productos, &cantidad](const Producto& producto) {
            if (producto.tieneStockBajo()) {
                InfoProducto& info = productos[cantidad];
                strcpy(info.nombre, producto.obtenerNombre());
                info.codigo = producto.obtenerCodigo();
                info.cantidad = producto.obtenerCantidad();
                cantidad++;
            }
        });
    }
    
    void obtenerTodosProductos(InfoProducto productos[], int& cantidad) const {
        cantidad = 0;
        
        listaProductos.recorrer([&productos, &cantidad](const Producto& producto) {
            InfoProducto& info = productos[cantidad];
            strcpy(info.nombre, producto.obtenerNombre());
            info.codigo = producto.obtenerCodigo();
            info.cantidad = producto.obtenerCantidad();
            cantidad++;
        });
    }
    
    bool actualizarStock(int codigo, int nuevaCantidad) {
        if (!validador.esCantidadValida(nuevaCantidad)) {
            return false;
        }
        
        Producto* producto = listaProductos.buscarPorCodigo(codigo);
        if (producto == nullptr) {
            return false;
        }
        
        producto->actualizarStock(nuevaCantidad);
        return true;
    }
    
    int obtenerCantidadTotal() const {
        return listaProductos.obtenerTamanio();
    }
    
    int obtenerCantidadStockBajo() const {
        int contador = 0;
        listaProductos.recorrer([&contador](const Producto& producto) {
            if (producto.tieneStockBajo()) {
                contador++;
            }
        });
        return contador;
    }
    
    void limpiarInventario() {
        listaProductos.limpiar();
    }
    
    void reiniciarSistema() {
        listaProductos.limpiar();
    }
};

#endif