#pragma once
#include "IInventario.h"
#include <memory>

class IInventarioService {
public:
    virtual ~IInventarioService() = default;
    virtual void actualizarStock(int almacen, int producto, int cantidad) = 0;
    virtual void procesarAlertas() = 0;
    virtual void reporteAgotados() = 0;
    virtual void reporteStockBajo() = 0;
    virtual void reporteAlmacenCritico() = 0;
    virtual void configurarUmbralGlobal(int umbral) = 0;
};