#include "../include/InventarioController.h"
#include "../include/InventarioService.h"
#include "../include/Almacen.h"
#include <iostream>

using namespace std;

class InventarioUI {
private:
    InventarioController controller;

public:
    InventarioUI() : controller(make_unique<InventarioService>(make_unique<Almacen>())) {}

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
        cout << "\n=== CONTROL DE INVENTARIO MULTI-SUCURSAL ===\n"
                  << "1. Registrar stock\n"
                  << "2. Detectar productos agotados\n"
                  << "3. Identificar almacén crítico\n"
                  << "4. Generar alertas de stock bajo\n"
                  << "5. Configurar umbral mínimo\n"
                  << "6. Ver inventario completo\n"
                  << "7. Ver inventario por almacén\n"
                  << "8. Cargar datos de prueba\n"
                  << "0. Salir\nOpción: ";
    }

    void procesarOpcion(int opcion) {
        switch (opcion) {
            case 1: registrarStock(); break;
            case 2: controller.reporteAgotados(); break;
            case 3: controller.reporteAlmacenCritico(); break;
            case 4: controller.procesarAlertas(); break;
            case 5: configurarUmbral(); break;
            case 6: controller.mostrarInventarioCompleto(); break;
            case 7: verInventarioAlmacen(); break;
            case 8: cargarDatosPrueba(); break;
            case 0: cout << "👋 Saliendo del sistema...\n"; break;
            default: cout << "❌ Opción inválida\n";
        }
    }

    void registrarStock() {
        int almacen, producto, cantidad;
        
        cout << "Almacén (0-5): ";
        if (!(cin >> almacen)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Entrada inválida para almacén");
        }
        
        cout << "Producto (0-14): ";
        if (!(cin >> producto)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Entrada inválida para producto");
        }
        
        cout << "Cantidad: ";
        if (!(cin >> cantidad)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Entrada inválida para cantidad");
        }
        
        controller.actualizarStock(almacen, producto, cantidad);
    }

    void configurarUmbral() {
        int umbral;
        cout << "Nuevo umbral mínimo: ";
        if (!(cin >> umbral)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Entrada inválida para umbral");
        }
        
        controller.configurarUmbralGlobal(umbral);
    }

    void verInventarioAlmacen() {
        int almacen;
        cout << "Almacén (0-5): ";
        if (!(cin >> almacen)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Entrada inválida para almacén");
        }
        
        controller.mostrarInventarioAlmacen(almacen);
    }

    void cargarDatosPrueba() {
        // Datos de prueba para demostrar funcionalidades
        controller.actualizarStock(0, 0, 100);  // Stock normal
        controller.actualizarStock(0, 1, 3);    // Stock bajo
        controller.actualizarStock(0, 2, 0);    // Agotado
        controller.actualizarStock(1, 0, 50);
        controller.actualizarStock(1, 1, 2);    // Stock bajo
        controller.actualizarStock(2, 0, 25);   // Almacén con menos stock
        controller.actualizarStock(3, 0, 75);
        controller.actualizarStock(4, 0, 80);
        controller.actualizarStock(5, 0, 90);
        
        cout << "✅ Datos de prueba cargados exitosamente\n";
        cout << "💡 Prueba las opciones 2, 3 y 4 para ver los reportes\n";
    }
};

int main() {
    cout << "🏢 Iniciando Sistema de Control de Inventario Multi-Sucursal\n";
    
    InventarioUI app;
    app.ejecutar();
    
    return 0;
}