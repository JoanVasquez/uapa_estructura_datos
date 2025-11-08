#include "../include/InventarioController.h"
#include "../include/InventarioService.h"
#include "../include/Almacen.h"
#include <iostream>

class InventarioUI {
private:
    InventarioController controller;

public:
    InventarioUI() : controller(std::make_unique<InventarioService>(std::make_unique<Almacen>())) {}

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
        std::cout << "\n=== CONTROL DE INVENTARIO MULTI-SUCURSAL ===\n"
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
            case 0: std::cout << "👋 Saliendo del sistema...\n"; break;
            default: std::cout << "❌ Opción inválida\n";
        }
    }

    void registrarStock() {
        int almacen, producto, cantidad;
        
        std::cout << "Almacén (0-5): ";
        if (!(std::cin >> almacen)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::invalid_argument("Entrada inválida para almacén");
        }
        
        std::cout << "Producto (0-14): ";
        if (!(std::cin >> producto)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::invalid_argument("Entrada inválida para producto");
        }
        
        std::cout << "Cantidad: ";
        if (!(std::cin >> cantidad)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::invalid_argument("Entrada inválida para cantidad");
        }
        
        controller.actualizarStock(almacen, producto, cantidad);
    }

    void configurarUmbral() {
        int umbral;
        std::cout << "Nuevo umbral mínimo: ";
        if (!(std::cin >> umbral)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::invalid_argument("Entrada inválida para umbral");
        }
        
        controller.configurarUmbralGlobal(umbral);
    }

    void verInventarioAlmacen() {
        int almacen;
        std::cout << "Almacén (0-5): ";
        if (!(std::cin >> almacen)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::invalid_argument("Entrada inválida para almacén");
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
        
        std::cout << "✅ Datos de prueba cargados exitosamente\n";
        std::cout << "💡 Prueba las opciones 2, 3 y 4 para ver los reportes\n";
    }
};

int main() {
    std::cout << "🏢 Iniciando Sistema de Control de Inventario Multi-Sucursal\n";
    
    InventarioUI app;
    app.ejecutar();
    
    return 0;
}