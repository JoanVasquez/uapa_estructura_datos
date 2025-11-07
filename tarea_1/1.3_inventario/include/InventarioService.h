#pragma once
#include "IInventarioService.h"

class InventarioService : public IInventarioService {
private:
    std::unique_ptr<IInventario> inventario;

public:
    explicit InventarioService(std::unique_ptr<IInventario> inv);
    
    void actualizarStock(int almacen, int producto, int cantidad) override;
    void procesarAlertas() override;
    void reporteAgotados() override;
    void reporteStockBajo() override;
    void reporteAlmacenCritico() override;
    void configurarUmbralGlobal(int umbral) override;
    
    // Métodos de consulta
    void mostrarInventarioCompleto();
    void mostrarInventarioAlmacen(int almacen);
};