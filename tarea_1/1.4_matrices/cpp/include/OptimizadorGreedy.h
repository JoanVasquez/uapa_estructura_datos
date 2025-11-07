#pragma once
#include "IOptimizador.h"

class OptimizadorGreedy : public IOptimizador {
private:
    static constexpr int NUM_ALMACENES = 6;
    static constexpr int NUM_PRODUCTOS = 15;
    
    std::array<std::array<int, NUM_PRODUCTOS>, NUM_ALMACENES> stock;
    std::array<std::array<int, NUM_ALMACENES>, NUM_ALMACENES> distancias;
    std::array<int, NUM_PRODUCTOS> umbrales;
    std::vector<Movimiento> movimientos;
    int costoTotal;
    
    void validarDatos() const;
    int encontrarMejorOrigen(int producto, int destino) const;
    void realizarMovimiento(int producto, int origen, int destino, int cantidad);

public:
    OptimizadorGreedy();
    
    std::vector<Movimiento> optimizar() override;
    void configurarStock(const std::array<std::array<int, 15>, 6>& stock) override;
    void configurarDistancias(const std::array<std::array<int, 6>, 6>& dist) override;
    void configurarUmbrales(const std::array<int, 15>& umbrales) override;
    int obtenerCostoTotal() const override { return costoTotal; }
};