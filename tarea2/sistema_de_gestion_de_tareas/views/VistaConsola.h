#ifndef VISTA_CONSOLA_H
#define VISTA_CONSOLA_H

#include "../controllers/TareasControlador.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class VistaConsola {
private:
    static const int MAX_TAREAS = 1000;
    
    void mostrarBienvenida() const {
        cout << "========================================" << endl;
        cout << "  SISTEMA DE GESTION DE TAREAS" << endl;
        cout << "  Organizacion por Prioridad" << endl;
        cout << "========================================" << endl;
        cout << endl;
    }
    
    void mostrarMenu() const {
        cout << "MENU PRINCIPAL:" << endl;
        cout << "----------------------------------------" << endl;
        cout << "  1. Agregar nueva tarea" << endl;
        cout << "  2. Ver tareas pendientes" << endl;
        cout << "  3. Ver todas las tareas" << endl;
        cout << "  4. Marcar tarea como completada" << endl;
        cout << "  5. Eliminar tareas completadas" << endl;
        cout << "  6. Ver estadisticas y tiempos" << endl;
        cout << "  7. Salir del programa" << endl;
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
    
    void leerDatosTarea(char nombre[], int& prioridad) const {
        cout << endl;
        cout << "Datos de la tarea:" << endl;
        cout << "Nombre: ";
        cin.getline(nombre, 200);
        
        cout << "Prioridad (1-10, donde 10 es maxima): ";
        cin >> prioridad;
        cin.ignore();
    }
    
    void procesarAgregar(TareasControlador& controlador) const {
        char nombre[200];
        int prioridad;
        
        leerDatosTarea(nombre, prioridad);
        
        RespuestaTareas respuesta = controlador.procesarAgregar(nombre, prioridad);
        
        cout << endl;
        if (respuesta.exito) {
            cout << "✓ " << respuesta.mensaje << endl;
            cout << "   Total de tareas: " << controlador.obtenerCantidadTotal() << endl;
        } else {
            cout << "✗ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void mostrarTablaTareas(InfoTarea tareas[], int cantidad, const char* titulo) const {
        cout << endl;
        cout << "========================================================================================================" << endl;
        cout << titulo << endl;
        cout << "========================================================================================================" << endl;
        cout << left << setw(8) << "ID" 
             << setw(12) << "PRIORIDAD" 
             << setw(60) << "NOMBRE"
             << setw(15) << "ESTADO" << endl;
        cout << "========================================================================================================" << endl;
        
        for (int i = 0; i < cantidad; i++) {
            cout << left << setw(8) << tareas[i].id
                 << setw(12) << tareas[i].prioridad
                 << setw(60) << tareas[i].nombre
                 << setw(15) << tareas[i].estado << endl;
        }
        
        cout << "========================================================================================================" << endl;
        cout << "Total: " << cantidad << " tarea(s)" << endl;
    }
    
    void procesarPendientes(TareasControlador& controlador) const {
        InfoTarea tareas[MAX_TAREAS];
        int cantidad;
        
        RespuestaTareas respuesta = controlador.procesarMostrarPendientes(tareas, cantidad);
        
        if (cantidad == 0) {
            cout << endl;
            cout << "ℹ " << respuesta.mensaje << endl;
            mostrarTiempo(respuesta.tiempoEjecucion);
            return;
        }
        
        mostrarTablaTareas(tareas, cantidad, "TAREAS PENDIENTES (Ordenadas por Prioridad)");
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarTodas(TareasControlador& controlador) const {
        InfoTarea tareas[MAX_TAREAS];
        int cantidad;
        
        RespuestaTareas respuesta = controlador.procesarMostrarTodas(tareas, cantidad);
        
        if (cantidad == 0) {
            cout << endl;
            cout << "ℹ " << respuesta.mensaje << endl;
            mostrarTiempo(respuesta.tiempoEjecucion);
            return;
        }
        
        mostrarTablaTareas(tareas, cantidad, "TODAS LAS TAREAS (Ordenadas por Prioridad)");
        
        int pendientes = controlador.obtenerCantidadPendientes();
        int completadas = controlador.obtenerCantidadCompletadas();
        
        cout << endl;
        cout << "Resumen: " << pendientes << " pendiente(s), " 
             << completadas << " completada(s)" << endl;
        
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarCompletar(TareasControlador& controlador) const {
        int id;
        cout << endl;
        cout << "Ingrese el ID de la tarea a completar: ";
        cin >> id;
        cin.ignore();
        
        RespuestaTareas respuesta = controlador.procesarCompletar(id);
        
        cout << endl;
        if (respuesta.exito) {
            cout << "✓ " << respuesta.mensaje << endl;
        } else {
            cout << "✗ " << respuesta.mensaje << endl;
        }
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarEliminar(TareasControlador& controlador) const {
        RespuestaTareas respuesta = controlador.procesarEliminarCompletadas();
        
        cout << endl;
        cout << "✓ " << respuesta.mensaje << endl;
        cout << "   Tareas restantes: " << controlador.obtenerCantidadTotal() << endl;
        mostrarTiempo(respuesta.tiempoEjecucion);
    }
    
    void procesarEstadisticas(TareasControlador& controlador) const {
        cout << endl;
        cout << "========================================" << endl;
        cout << "ESTADISTICAS Y TIEMPOS DE EJECUCION" << endl;
        cout << "========================================" << endl;
        cout << "Total de tareas: " << controlador.obtenerCantidadTotal() << endl;
        cout << "Tareas pendientes: " << controlador.obtenerCantidadPendientes() << endl;
        cout << "Tareas completadas: " << controlador.obtenerCantidadCompletadas() << endl;
        cout << fixed << setprecision(6);
        cout << "Tiempo total acumulado: " << controlador.obtenerTiempoTotalEjecucion() << " ms" << endl;
        cout << "========================================" << endl;
        
        // Mostrar tiempos por operación si hay datos
        if (controlador.obtenerTiempoTotalEjecucion() > 0) {
            cout << endl;
            cout << "DESGLOSE DE TIEMPOS:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Este tiempo incluye todas las operaciones realizadas:" << endl;
            cout << "- Agregar tareas" << endl;
            cout << "- Mostrar tareas pendientes" << endl;
            cout << "- Mostrar todas las tareas" << endl;
            cout << "- Completar tareas" << endl;
            cout << "- Eliminar tareas completadas" << endl;
            cout << "========================================" << endl;
        }
    }
    
    int leerOpcionMenu() const {
        int opcion;
        cout << "Seleccione una opcion (1-7): ";
        cin >> opcion;
        cin.ignore();
        return opcion;
    }
    
public:
    void ejecutar() {
        TareasControlador controlador;
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
                    procesarPendientes(controlador);
                    break;
                case 3:
                    procesarTodas(controlador);
                    break;
                case 4:
                    procesarCompletar(controlador);
                    break;
                case 5:
                    procesarEliminar(controlador);
                    break;
                case 6:
                    procesarEstadisticas(controlador);
                    break;
                case 7:
                    continuar = false;
                    break;
                default:
                    cout << "✗ Opcion no valida. Por favor, seleccione una opcion del 1 al 7." << endl;
                    break;
            }
            
            if (opcion != 7) {
                cout << endl;
                cout << "Presione Enter para continuar...";
                cin.get();
            }
        }
        
        cout << endl;
        cout << "========================================" << endl;
        cout << "RESUMEN FINAL" << endl;
        cout << "========================================" << endl;
        cout << "Total de tareas: " << controlador.obtenerCantidadTotal() << endl;
        cout << "Tareas pendientes: " << controlador.obtenerCantidadPendientes() << endl;
        cout << "Tareas completadas: " << controlador.obtenerCantidadCompletadas() << endl;
        cout << "Tiempo total: " << fixed << setprecision(6) 
             << controlador.obtenerTiempoTotalEjecucion() << " ms" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Gracias por usar el sistema de gestion de tareas." << endl;
        cout << "¡Que tenga un excelente dia!" << endl;
        cout << "========================================" << endl;
    }
};

#endif