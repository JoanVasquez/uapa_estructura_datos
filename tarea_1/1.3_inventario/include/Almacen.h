#pragma once
#include "IInventario.h"
#include <array>

class Almacen : public IInventario {
private:
    static constexpr int NUM_ALMACENES = 6;
    static constexpr int NUM_PRODUCTOS = 15;
    static constexpr int UMBRAL_DEFAULT = 5;
    
    std::array<std::array<int, NUM_PRODUCTOS>, NUM_ALMACENES> stock;
    int umbralMinimo;
    
    void validarIndices(int almacen, int producto) const;
    void validarAlmacen(int almacen) const;

public:
    Almacen();
    
    void registrarStock(int almacen, int producto, int cantidad) override;
    int obtenerStock(int almacen, int producto) const override;
    std::vector<int> detectarAgotados(int almacen) const override;
    int almacenMenorStock() const override;
    std::vector<AlertaStock> generarAlertas() const override;
    void configurarUmbral(int umbral) override;
    int calcularStockTotal(int almacen) const override;
    
    // Métodos adicionales para UI
    void mostrarStock() const;
    void mostrarStockAlmacen(int almacen) const;
};