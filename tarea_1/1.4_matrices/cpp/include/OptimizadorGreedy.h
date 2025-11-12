#pragma once
#include "IOptimizador.h"

using namespace std;

// Implementación del algoritmo greedy usando matrices bidimensionales estáticas
// Maneja redistribución óptima con estructuras repetitivas anidadas
class OptimizadorGreedy : public IOptimizador {
private:
    // Matrices bidimensionales estáticas
    int stock[NUM_ALMACENES][NUM_PRODUCTOS];        // Matriz de stock por almacén/producto
    int distancias[NUM_ALMACENES][NUM_ALMACENES];   // Matriz de distancias entre almacenes
    int umbrales[NUM_PRODUCTOS];                    // Arreglo unidimensional de umbrales
    
    Movimiento movimientos[MAX_MOVIMIENTOS];        // Arreglo de movimientos resultantes
    int totalMovimientos;                           // Contador de movimientos
    int costoTotal;                                 // Costo total acumulado
    
    // Funciones auxiliares para manipulación de matrices
    void validarDatos() const;
    int encontrarMejorOrigen(int producto, int destino) const;
    void realizarMovimiento(int producto, int origen, int destino, int cantidad, int indice);
    void inicializarMatrices();

public:
    OptimizadorGreedy();
    
    // Implementación con arreglos estáticos
    int optimizar(Movimiento movimientos[]) override;
    void configurarStock(int stock[NUM_ALMACENES][NUM_PRODUCTOS]) override;
    void configurarDistancias(int distancias[NUM_ALMACENES][NUM_ALMACENES]) override;
    void configurarUmbrales(int umbrales[NUM_PRODUCTOS]) override;
    int obtenerCostoTotal() const override { return costoTotal; }
};