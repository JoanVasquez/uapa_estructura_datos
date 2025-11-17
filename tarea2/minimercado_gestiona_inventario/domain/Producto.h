#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <cstring>

// Entidad: Producto - Representa un producto del inventario
class Producto {
private:
    static const int MAX_NOMBRE = 100;
    int codigo;
    char nombre[MAX_NOMBRE];
    int cantidad;
    
public:
    Producto() : codigo(0), cantidad(0) {
        nombre[0] = '\0';
    }
    
    Producto(int codigoParam, const char* nombreParam, int cantidadParam) {
        codigo = codigoParam;
        establecerNombre(nombreParam);
        cantidad = cantidadParam;
    }
    
    void establecerNombre(const char* nombreParam) {
        if (nombreParam != nullptr) {
            strncpy(nombre, nombreParam, MAX_NOMBRE - 1);
            nombre[MAX_NOMBRE - 1] = '\0';
        }
    }
    
    void establecerCodigo(int codigoParam) {
        codigo = codigoParam;
    }
    
    void establecerCantidad(int cantidadParam) {
        cantidad = cantidadParam;
    }
    
    const char* obtenerNombre() const {
        return nombre;
    }
    
    int obtenerCodigo() const {
        return codigo;
    }
    
    int obtenerCantidad() const {
        return cantidad;
    }
    
    bool tieneStockBajo() const {
        return cantidad < 5;
    }
    
    bool esValido() const {
        return codigo > 0 && nombre[0] != '\0' && cantidad >= 0;
    }
    
    void actualizarStock(int nuevaCantidad) {
        cantidad = nuevaCantidad;
    }
};

#endif