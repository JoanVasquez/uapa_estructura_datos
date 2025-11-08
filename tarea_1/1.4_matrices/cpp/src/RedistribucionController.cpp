#include "../include/RedistribucionController.h"

using namespace std;

// Constructor: Inyección de dependencia del servicio de redistribución
RedistribucionController::RedistribucionController(unique_ptr<RedistribucionService> srv)
    : service(move(srv)) {}

// Ejecuta algoritmo de optimización greedy para redistribución
void RedistribucionController::ejecutarOptimizacion() {
    service->ejecutarOptimizacion();
}

// Muestra resultados de la optimización con costos y movimientos
void RedistribucionController::mostrarResultados() {
    service->mostrarResultados();
}

// Carga datos de prueba predefinidos para demostración
void RedistribucionController::cargarDatosPrueba() {
    service->cargarDatosPrueba();
}

// Permite configuración manual de matrices de entrada
void RedistribucionController::configurarMatrices() {
    service->configurarMatrices();
}