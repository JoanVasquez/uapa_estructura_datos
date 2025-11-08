#pragma once
#include "InventarioService.h"
#include <memory>

using namespace std;

/**
 * Controller para sistema de inventario multi-sucursal.
 * Coordina operaciones de 6 almacenes con 15 productos cada uno.
 * Maneja matriz stock[6][15] y genera reportes de alertas.
 */
class InventarioController {
private:
    unique_ptr<InventarioService> service; // Servicio de inventario inyectado

public:
    explicit InventarioController(unique_ptr<InventarioService> srv);
    
    // Operaciones de actualización
    void actualizarStock(int almacen, int producto, int cantidad);
    void configurarUmbralGlobal(int umbral);
    
    // Generación de reportes y alertas
    void procesarAlertas();
    void reporteAgotados();
    void reporteAlmacenCritico();
    
    // Visualización de inventario
    void mostrarInventarioCompleto();
    void mostrarInventarioAlmacen(int almacen);
};