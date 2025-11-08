#pragma once
#include "RedistribucionService.h"
#include <memory>

using namespace std;

/**
 * Controller para sistema de reasignación óptima de productos.
 * Coordina algoritmo greedy para minimizar costos de redistribución.
 * Maneja matrices de stock[6][15], distancias[6][6] y umbrales[15].
 */
class RedistribucionController {
private:
    unique_ptr<RedistribucionService> service; // Servicio de optimización

public:
    explicit RedistribucionController(unique_ptr<RedistribucionService> srv);
    
    // Operaciones de optimización
    void ejecutarOptimizacion();
    void mostrarResultados();
    
    // Configuración de datos
    void cargarDatosPrueba();
    void configurarMatrices();
};