#include "../include/RedistribucionService.h"
#include "../include/OptimizadorGreedy.h"
#include <iostream>

class RedistribucionUI {
private:
    RedistribucionService service;

public:
    RedistribucionUI() : service(std::make_unique<OptimizadorGreedy>()) {}

    void ejecutar() {
        int opcion;
        do {
            mostrarMenu();
            std::cin >> opcion;
            try {
                procesarOpcion(opcion);
            } catch (const std::exception& e) {
                std::cout << "❌ Error: " << e.what() << std::endl;
            }
        } while (opcion != 0);
    }

private:
    void mostrarMenu() {
        std::cout << "\n=== REASIGNACIÓN ÓPTIMA DE PRODUCTOS ===\n"
                  << "1. Configurar matrices manualmente\n"
                  << "2. Cargar datos de prueba\n"
                  << "3. Ejecutar optimización\n"
                  << "4. Mostrar resultados\n"
                  << "0. Salir\nOpción: ";
    }

    void procesarOpcion(int opcion) {
        switch (opcion) {
            case 1: service.configurarMatrices(); break;
            case 2: service.cargarDatosPrueba(); break;
            case 3: service.ejecutarOptimizacion(); break;
            case 4: service.mostrarResultados(); break;
            case 0: std::cout << "👋 Saliendo del sistema...\n"; break;
            default: std::cout << "❌ Opción inválida\n";
        }
    }
};

int main() {
    std::cout << "🚚 Sistema de Reasignación Óptima de Productos\n";
    
    RedistribucionUI app;
    app.ejecutar();
    
    return 0;
}