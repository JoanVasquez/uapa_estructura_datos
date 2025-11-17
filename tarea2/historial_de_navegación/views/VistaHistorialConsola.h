#ifndef VISTA_HISTORIAL_CONSOLA_H
#define VISTA_HISTORIAL_CONSOLA_H

#include "../controllers/HistorialControlador.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class VistaHistorialConsola {
private:
    static const int MAX_PAGINAS = 1000;
    
    void mostrarBienvenida() const {
        cout << "========================================" << endl;
        cout << "    SISTEMA DE HISTORIAL DE NAVEGACION" << endl;
        cout << "         NAVEGADOR WEB - LISTA DOBLE" << endl;
        cout << "========================================" << endl;
        cout << endl;
    }
    
    void mostrarMenu() const {
        cout << "MENU PRINCIPAL:" << endl;
        cout << "----------------------------------------" << endl;
        cout << "  1. Agregar nueva pagina al historial" << endl;
        cout << "  2. Navegar ATRAS" << endl;
        cout << "  3. Navegar ADELANTE" << endl;
        cout << "  4. Mostrar pagina actual" << endl;
        cout << "  5. Eliminar URL del historial" << endl;
        cout << "  6. Mostrar historial completo (reverso)" << endl;
        cout << "  7. Ver estadisticas y tiempos" << endl;
        cout << "  8. Salir del programa" << endl;
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
    
    void leerDatosPagina(char url[], char fechaHora[]) const {
        cout << endl;
        cout << "Datos de la pagina:" << endl;
        cout << "URL: ";
        cin.getline(url, 200);
        
        cout << "Fecha y hora (ej: 2024-01-15 14:30): ";
        cin.getline(fechaHora, 20);
    }
    
    void procesarAgregar(HistorialControlador& controlador) const {
        char url[200];
        char fechaHora[20];
        
        leerDatosPagina(url, fechaHora);
        
        RespuestaHistorial respuesta = controlador.procesarAgregar(url, fechaHora);
        
        cout << endl;
        if (respuesta.exito) {
            cout << "✓ " << respuesta.mensaje << endl;
            cout << "   Total en historial: " << controlador.obtenerCantidadTotal() << endl;
        } else {
            cout << "✗ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void mostrarTablaPaginas(InfoPagina paginas[], int cantidad, const char* titulo) const {
        cout << endl;
        cout << "================================================================================" << endl;
        cout << titulo << endl;
        cout << "================================================================================" << endl;
        cout << left << setw(50) << "URL" 
             << setw(20) << "FECHA/HORA" << endl;
        cout << "================================================================================" << endl;
        
        for (int i = 0; i < cantidad; i++) {
            cout << left << setw(50) << paginas[i].url
                 << setw(20) << paginas[i].fechaHora << endl;
        }
        
        cout << "================================================================================" << endl;
        cout << "Total: " << cantidad << " pagina(s)" << endl;
    }
    
    void procesarNavegarAtras(HistorialControlador& controlador) const {
        RespuestaHistorial respuesta = controlador.procesarNavegarAtras();
        
        cout << endl;
        if (respuesta.exito) {
            cout << "↶ " << respuesta.mensaje << endl;
        } else {
            cout << "ℹ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarNavegarAdelante(HistorialControlador& controlador) const {
        RespuestaHistorial respuesta = controlador.procesarNavegarAdelante();
        
        cout << endl;
        if (respuesta.exito) {
            cout << "↷ " << respuesta.mensaje << endl;
        } else {
            cout << "ℹ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarPaginaActual(HistorialControlador& controlador) const {
        RespuestaHistorial respuesta = controlador.obtenerPaginaActual();
        
        cout << endl;
        if (respuesta.exito) {
            cout << "📍 " << respuesta.mensaje << endl;
        } else {
            cout << "ℹ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarEliminarUrl(HistorialControlador& controlador) const {
        char url[200];
        
        cout << endl;
        cout << "Eliminar URL del historial:" << endl;
        cout << "URL a eliminar: ";
        cin.getline(url, 200);
        
        RespuestaHistorial respuesta = controlador.procesarEliminarUrl(url);
        
        cout << endl;
        if (respuesta.exito) {
            cout << "🗑️ " << respuesta.mensaje << endl;
            cout << "   Paginas restantes: " << controlador.obtenerCantidadTotal() << endl;
        } else {
            cout << "✗ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarHistorialReverso(HistorialControlador& controlador) const {
        InfoPagina paginas[MAX_PAGINAS];
        int cantidad;
        
        RespuestaHistorial respuesta = controlador.procesarMostrarReverso(paginas, cantidad);
        
        if (cantidad == 0) {
            cout << endl;
            cout << "ℹ " << respuesta.mensaje << endl;
            mostrarTiempo(respuesta.tiempoEjecucion);
            return;
        }
        
        mostrarTablaPaginas(paginas, cantidad, "HISTORIAL DE NAVEGACION (Orden Cronologico Inverso)");
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarEstadisticas(HistorialControlador& controlador) const {
        cout << endl;
        cout << "========================================" << endl;
        cout << "ESTADISTICAS Y TIEMPOS DE EJECUCION" << endl;
        cout << "========================================" << endl;
        cout << "Total de paginas en historial: " << controlador.obtenerCantidadTotal() << endl;
        cout << fixed << setprecision(6);
        cout << "Tiempo total acumulado: " << controlador.obtenerTiempoTotalEjecucion() << " ms" << endl;
        cout << "========================================" << endl;
    }
    
    int leerOpcionMenu() const {
        int opcion;
        cout << "Seleccione una opcion (1-8): ";
        cin >> opcion;
        cin.ignore();
        return opcion;
    }
    
public:
    void ejecutar() {
        HistorialControlador controlador;
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
                    procesarNavegarAtras(controlador);
                    break;
                case 3:
                    procesarNavegarAdelante(controlador);
                    break;
                case 4:
                    procesarPaginaActual(controlador);
                    break;
                case 5:
                    procesarEliminarUrl(controlador);
                    break;
                case 6:
                    procesarHistorialReverso(controlador);
                    break;
                case 7:
                    procesarEstadisticas(controlador);
                    break;
                case 8:
                    continuar = false;
                    break;
                default:
                    cout << "✗ Opcion no valida. Por favor, seleccione una opcion del 1 al 8." << endl;
                    break;
            }
            
            if (opcion != 8) {
                cout << endl;
                cout << "Presione Enter para continuar...";
                cin.get();
            }
        }
        
        cout << endl;
        cout << "========================================" << endl;
        cout << "RESUMEN FINAL" << endl;
        cout << "========================================" << endl;
        cout << "Total de paginas en historial: " << controlador.obtenerCantidadTotal() << endl;
        cout << "Tiempo total: " << fixed << setprecision(6) 
             << controlador.obtenerTiempoTotalEjecucion() << " ms" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Gracias por usar el sistema de historial de navegacion." << endl;
        cout << "¡Hasta pronto!" << endl;
        cout << "========================================" << endl;
    }
};

#endif