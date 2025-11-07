#include "../include/OptimizadorGreedy.h"
#include <stdexcept>
#include <algorithm>
#include <climits>

OptimizadorGreedy::OptimizadorGreedy() : costoTotal(0) {
    for (auto& almacen : stock) almacen.fill(0);
    for (auto& fila : distancias) fila.fill(1);
    umbrales.fill(5);
}

void OptimizadorGreedy::validarDatos() const {
    for (int i = 0; i < NUM_ALMACENES; ++i) {
        for (int j = 0; j < NUM_ALMACENES; ++j) {
            if (distancias[i][j] < 0) {
                throw std::invalid_argument("Las distancias no pueden ser negativas");
            }
        }
    }
}

void OptimizadorGreedy::configurarStock(const std::array<std::array<int, 15>, 6>& nuevoStock) {
    stock = nuevoStock;
}

void OptimizadorGreedy::configurarDistancias(const std::array<std::array<int, 6>, 6>& dist) {
    distancias = dist;
    validarDatos();
}

void OptimizadorGreedy::configurarUmbrales(const std::array<int, 15>& nuevosUmbrales) {
    umbrales = nuevosUmbrales;
}

std::vector<Movimiento> OptimizadorGreedy::optimizar() {
    movimientos.clear();
    costoTotal = 0;
    
    for (int producto = 0; producto < NUM_PRODUCTOS; ++producto) {
        for (int destino = 0; destino < NUM_ALMACENES; ++destino) {
            int faltante = umbrales[producto] - stock[destino][producto];
            
            while (faltante > 0) {
                int origen = encontrarMejorOrigen(producto, destino);
                if (origen == -1) break;
                
                int disponible = stock[origen][producto] - umbrales[producto];
                if (disponible <= 0) break;
                
                int cantidad = std::min(faltante, disponible);
                realizarMovimiento(producto, origen, destino, cantidad);
                faltante -= cantidad;
            }
        }
    }
    
    return movimientos;
}

int OptimizadorGreedy::encontrarMejorOrigen(int producto, int destino) const {
    int mejorOrigen = -1;
    int menorCosto = INT_MAX;
    
    for (int origen = 0; origen < NUM_ALMACENES; ++origen) {
        if (origen != destino && stock[origen][producto] > umbrales[producto]) {
            if (distancias[origen][destino] < menorCosto) {
                menorCosto = distancias[origen][destino];
                mejorOrigen = origen;
            }
        }
    }
    
    return mejorOrigen;
}

void OptimizadorGreedy::realizarMovimiento(int producto, int origen, int destino, int cantidad) {
    stock[origen][producto] -= cantidad;
    stock[destino][producto] += cantidad;
    
    int costo = cantidad * distancias[origen][destino];
    costoTotal += costo;
    
    movimientos.emplace_back(producto, origen, destino, cantidad, costo);
}