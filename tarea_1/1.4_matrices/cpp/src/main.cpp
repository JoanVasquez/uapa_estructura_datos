#include "../include/RedistribucionController.h"
#include "../include/RedistribucionService.h"
#include "../include/OptimizadorGreedy.h"
#include <iostream>

using namespace std;

class RedistribucionUI {
private:
    RedistribucionController controller;

public:
    RedistribucionUI() : controller(make_unique<RedistribucionService>(make_unique<OptimizadorGreedy>())) {}

    void ejecutar() {
        int opcion;
        do {
            mostrarMenu();
            cin >> opcion;
            try {
                procesarOpcion(opcion);
            } catch (const exception& e) {
                cout << "❌ Error: " << e.what() << endl;
            }
        } while (opcion != 0);
    }

private:
    void mostrarMenu() {
        cout << "\n=== REASIGNACIÓN ÓPTIMA DE PRODUCTOS ===\n"
                  << "1. Configurar matrices manualmente\n"
                  << "2. Cargar datos de prueba\n"
                  << "3. Ejecutar optimización\n"
                  << "4. Mostrar resultados\n"
                  << "0. Salir\nOpción: ";
    }

    void procesarOpcion(int opcion) {
        switch (opcion) {
            case 1: controller.configurarMatrices(); break;
            case 2: controller.cargarDatosPrueba(); break;
            case 3: controller.ejecutarOptimizacion(); break;
            case 4: controller.mostrarResultados(); break;
            case 0: cout << "👋 Saliendo del sistema...\n"; break;
            default: cout << "❌ Opción inválida\n";
        }
    }
};

int main() {
    cout << "🚚 Sistema de Reasignación Óptima de Productos\n";
    
    RedistribucionUI app;
    app.ejecutar();
    
    return 0;
}