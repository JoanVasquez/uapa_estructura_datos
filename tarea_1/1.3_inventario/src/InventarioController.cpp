#include "../include/InventarioController.h"

using namespace std;

// Constructor: Inyección de dependencia del servicio de inventario
InventarioController::InventarioController(unique_ptr<InventarioService> srv)
    : service(move(srv)) {}

// Actualiza stock de producto específico en almacén
void InventarioController::actualizarStock(int almacen, int producto, int cantidad) {
    service->actualizarStock(almacen, producto, cantidad);
}

// Procesa y muestra alertas de stock bajo
void InventarioController::procesarAlertas() {
    service->procesarAlertas();
}

// Genera reporte de productos agotados por almacén
void InventarioController::reporteAgotados() {
    service->reporteAgotados();
}

// Identifica almacén con menor stock total
void InventarioController::reporteAlmacenCritico() {
    service->reporteAlmacenCritico();
}

// Configura umbral mínimo global para alertas
void InventarioController::configurarUmbralGlobal(int umbral) {
    service->configurarUmbralGlobal(umbral);
}

// Muestra inventario completo de todos los almacenes
void InventarioController::mostrarInventarioCompleto() {
    service->mostrarInventarioCompleto();
}

// Muestra inventario de un almacén específico
void InventarioController::mostrarInventarioAlmacen(int almacen) {
    service->mostrarInventarioAlmacen(almacen);
}