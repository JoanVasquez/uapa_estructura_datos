#ifndef VISTA_INVENTARIO_CONSOLA_H
#define VISTA_INVENTARIO_CONSOLA_H

#include "../controllers/InventarioControlador.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class VistaInventarioConsola {
private:
    static const int MAX_PRODUCTOS = 1000;
    
    void mostrarBienvenida() const {
        cout << "========================================" << endl;
        cout << "  SISTEMA DE GESTION DE INVENTARIO" << endl;
        cout << "      MINIMERCADO - STOCK BAJO" << endl;
        cout << "========================================" << endl;
        cout << endl;
    }
    
    void mostrarMenu() const {
        cout << "MENU PRINCIPAL:" << endl;
        cout << "----------------------------------------" << endl;
        cout << "  1. Agregar nuevo producto" << endl;
        cout << "  2. Ver productos con stock bajo (<5)" << endl;
        cout << "  3. Ver todos los productos" << endl;
        cout << "  4. Actualizar stock de producto" << endl;
        cout << "  5. Ver estadisticas y tiempos" << endl;
        cout << "  6. Salir del programa" << endl;
        cout << "========================================" << endl;
        cout << endl;
    }
    
    void mostrarTiempo(double tiempo) const {
        cout << fixed << setprecision(6);
        if (tiempo < 0.001) {
            cout << "   [Tiempo: < 0.001 ms]" << endl;
        } else {
            cout << "   [Tiempo: " << tiempo << " ms]" << endl;
        }
    }
    
    void leerDatosProducto(int& codigo, char nombre[], int& cantidad) const {
        cout << endl;
        cout << "Datos del producto:" << endl;
        cout << "Codigo: ";
        cin >> codigo;
        cin.ignore();
        
        cout << "Nombre: ";
        cin.getline(nombre, 100);
        
        cout << "Cantidad en stock: ";
        cin >> cantidad;
        cin.ignore();
    }
    
    void procesarAgregar(InventarioControlador& controlador) const {
        int codigo, cantidad;
        char nombre[100];
        
        leerDatosProducto(codigo, nombre, cantidad);
        
        RespuestaInventario respuesta = controlador.procesarAgregar(codigo, nombre, cantidad);
        
        cout << endl;
        if (respuesta.exito) {
            cout << "✓ " << respuesta.mensaje << endl;
            cout << "   Total de productos: " << controlador.obtenerCantidadTotal() << endl;
        } else {
            cout << "✗ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void mostrarTablaProductos(InfoProducto productos[], int cantidad, const char* titulo) const {
        cout << endl;
        cout << "========================================================================" << endl;
        cout << titulo << endl;
        cout << "========================================================================" << endl;
        cout << left << setw(10) << "CODIGO" 
             << setw(40) << "NOMBRE"
             << setw(15) << "CANTIDAD" 
             << setw(15) << "ESTADO" << endl;
        cout << "========================================================================" << endl;
        
        for (int i = 0; i < cantidad; i++) {
            cout << left << setw(10) << productos[i].codigo
                 << setw(40) << productos[i].nombre
                 << setw(15) << productos[i].cantidad;
            
            // Mostrar estado del stock
            if (productos[i].cantidad < 5) {
                cout << setw(15) << "STOCK BAJO";
            } else if (productos[i].cantidad == 0) {
                cout << setw(15) << "AGOTADO";
            } else {
                cout << setw(15) << "NORMAL";
            }
            cout << endl;
        }
        
        cout << "========================================================================" << endl;
        cout << "Total: " << cantidad << " producto(s)" << endl;
    }
    
    void procesarStockBajo(InventarioControlador& controlador) const {
        InfoProducto productos[MAX_PRODUCTOS];
        int cantidad;
        
        RespuestaInventario respuesta = controlador.procesarMostrarStockBajo(productos, cantidad);
        
        if (cantidad == 0) {
            cout << endl;
            cout << "ℹ " << respuesta.mensaje << endl;
            mostrarTiempo(respuesta.tiempoEjecucion);
            return;
        }
        
        mostrarTablaProductos(productos, cantidad, "PRODUCTOS CON STOCK BAJO (< 5 UNIDADES)");
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarTodos(InventarioControlador& controlador) const {
        InfoProducto productos[MAX_PRODUCTOS];
        int cantidad;
        
        RespuestaInventario respuesta = controlador.procesarMostrarTodos(productos, cantidad);
        
        if (cantidad == 0) {
            cout << endl;
            cout << "ℹ " << respuesta.mensaje << endl;
            mostrarTiempo(respuesta.tiempoEjecucion);
            return;
        }
        
        mostrarTablaProductos(productos, cantidad, "TODOS LOS PRODUCTOS - INVENTARIO COMPLETO");
        
        int stockBajo = controlador.obtenerCantidadStockBajo();
        
        cout << endl;
        cout << "Resumen: " << stockBajo << " producto(s) con stock bajo" << endl;
        
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarActualizarStock(InventarioControlador& controlador) const {
        int codigo, nuevaCantidad;
        
        cout << endl;
        cout << "Actualizar stock de producto:" << endl;
        cout << "Codigo del producto: ";
        cin >> codigo;
        cin.ignore();
        
        cout << "Nueva cantidad en stock: ";
        cin >> nuevaCantidad;
        cin.ignore();
        
        RespuestaInventario respuesta = controlador.procesarActualizarStock(codigo, nuevaCantidad);
        
        cout << endl;
        if (respuesta.exito) {
            cout << "✓ " << respuesta.mensaje << endl;
        } else {
            cout << "✗ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarEstadisticas(InventarioControlador& controlador) const {
        cout << endl;
        cout << "========================================" << endl;
        cout << "ESTADISTICAS Y TIEMPOS DE EJECUCION" << endl;
        cout << "========================================" << endl;
        cout << "Total de productos: " << controlador.obtenerCantidadTotal() << endl;
        cout << "Productos con stock bajo: " << controlador.obtenerCantidadStockBajo() << endl;
        cout << fixed << setprecision(6);
        cout << "Tiempo total acumulado: " << controlador.obtenerTiempoTotalEjecucion() << " ms" << endl;
        cout << "========================================" << endl;
    }
    
    int leerOpcionMenu() const {
        int opcion;
        cout << "Seleccione una opcion (1-6): ";
        cin >> opcion;
        cin.ignore();
        return opcion;
    }
    
public:
    void ejecutar() {
        InventarioControlador controlador;
        bool continuar = true;
        
        mostrarBienvenida();
        
        while (continuar) {
            mostrarMenu();
            int opcion = leerOpcionMenu();
            
            switch (opcion) {
                case 1:
                    procesarAgregar(controlador);
                    break;
                case 2:
                    procesarStockBajo(controlador);
                    break;
                case 3:
                    procesarTodos(controlador);
                    break;
                case 4:
                    procesarActualizarStock(controlador);
                    break;
                case 5:
                    procesarEstadisticas(controlador);  // CORREGIDO: era controlarioControlador
                    break;
                case 6:
                    continuar = false;
                    break;
                default:
                    cout << "✗ Opcion no valida. Por favor, seleccione una opcion del 1 al 6." << endl;
                    break;
            }
            
            if (opcion != 6) {
                cout << endl;
                cout << "Presione Enter para continuar...";
                cin.get();
            }
        }
        
        cout << endl;
        cout << "========================================" << endl;
        cout << "RESUMEN FINAL" << endl;
        cout << "========================================" << endl;
        cout << "Total de productos: " << controlador.obtenerCantidadTotal() << endl;
        cout << "Productos con stock bajo: " << controlador.obtenerCantidadStockBajo() << endl;
        cout << "Tiempo total: " << fixed << setprecision(6) 
             << controlador.obtenerTiempoTotalEjecucion() << " ms" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Gracias por usar el sistema de gestion de inventario." << endl;
        cout << "¡Hasta pronto!" << endl;
        cout << "========================================" << endl;
    }
};

#endif