#pragma once
#include "Movimiento.h"

using namespace std;

// Interfaz para optimizador que maneja matrices bidimensionales estáticas
// Implementa algoritmos de redistribución con manipulación directa de matrices
class IOptimizador {
public:
    static const int NUM_ALMACENES = 6;  // Filas de las matrices
    static const int NUM_PRODUCTOS = 15; // Columnas de matriz stock
    static const int MAX_MOVIMIENTOS = 100; // Máximo de movimientos
    
    virtual ~IOptimizador() = default;
    
    // Optimización que llena arreglo de movimientos
    virtual int optimizar(Movimiento movimientos[]) = 0;
    
    // Configuración de matrices bidimensionales estáticas
    virtual void configurarStock(int stock[NUM_ALMACENES][NUM_PRODUCTOS]) = 0;
    virtual void configurarDistancias(int distancias[NUM_ALMACENES][NUM_ALMACENES]) = 0;
    virtual void configurarUmbrales(int umbrales[NUM_PRODUCTOS]) = 0;
    
    virtual int obtenerCostoTotal() const = 0;
};