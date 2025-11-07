#pragma once
#include "IOptimizador.h"
#include <memory>

class RedistribucionService {
private:
    std::unique_ptr<IOptimizador> optimizador;

public:
    explicit RedistribucionService(std::unique_ptr<IOptimizador> opt);
    
    void ejecutarOptimizacion();
    void mostrarResultados() const;
    void cargarDatosPrueba();
    void configurarMatrices();
};