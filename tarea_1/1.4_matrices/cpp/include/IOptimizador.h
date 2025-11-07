#pragma once
#include "Movimiento.h"
#include <vector>
#include <array>

class IOptimizador {
public:
    virtual ~IOptimizador() = default;
    virtual std::vector<Movimiento> optimizar() = 0;
    virtual void configurarStock(const std::array<std::array<int, 15>, 6>& stock) = 0;
    virtual void configurarDistancias(const std::array<std::array<int, 6>, 6>& dist) = 0;
    virtual void configurarUmbrales(const std::array<int, 15>& umbrales) = 0;
    virtual int obtenerCostoTotal() const = 0;
};