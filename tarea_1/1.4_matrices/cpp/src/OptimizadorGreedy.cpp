#include "../include/OptimizadorGreedy.h"
#include <climits>
#include <stdexcept>

using namespace std;

// Constructor: inicializa matrices bidimensionales estáticas
OptimizadorGreedy::OptimizadorGreedy() : totalMovimientos(0), costoTotal(0) {
    inicializarMatrices();
}

// Inicializa todas las matrices con valores por defecto
void OptimizadorGreedy::inicializarMatrices() {
    // Inicializar matriz de stock con ceros usando bucles anidados
    for (int i = 0; i < NUM_ALMACENES; i++) {
        for (int j = 0; j < NUM_PRODUCTOS; j++) {
            stock[i][j] = 0;
        }
    }
    
    // Inicializar matriz de distancias con unos
    for (int i = 0; i < NUM_ALMACENES; i++) {
        for (int j = 0; j < NUM_ALMACENES; j++) {
            distancias[i][j] = (i == j) ? 0 : 1;
        }
    }
    
    // Inicializar arreglo de umbrales
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        umbrales[i] = 5;
    }
}

// Valida matriz de distancias usando bucles anidados
void OptimizadorGreedy::validarDatos() const {
    for (int i = 0; i < NUM_ALMACENES; ++i) {
        for (int j = 0; j < NUM_ALMACENES; ++j) {
            if (distancias[i][j] < 0) {
                throw invalid_argument("Las distancias no pueden ser negativas");
            }
        }
    }
}

// Copia matriz de stock usando bucles anidados
void OptimizadorGreedy::configurarStock(int nuevoStock[NUM_ALMACENES][NUM_PRODUCTOS]) {
    for (int i = 0; i < NUM_ALMACENES; i++) {
        for (int j = 0; j < NUM_PRODUCTOS; j++) {
            stock[i][j] = nuevoStock[i][j];
        }
    }
}

// Copia matriz de distancias usando bucles anidados
void OptimizadorGreedy::configurarDistancias(int dist[NUM_ALMACENES][NUM_ALMACENES]) {
    for (int i = 0; i < NUM_ALMACENES; i++) {
        for (int j = 0; j < NUM_ALMACENES; j++) {
            distancias[i][j] = dist[i][j];
        }
    }
    validarDatos();
}

// Copia arreglo de umbrales usando bucle simple
void OptimizadorGreedy::configurarUmbrales(int nuevosUmbrales[NUM_PRODUCTOS]) {
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        umbrales[i] = nuevosUmbrales[i];
    }
}

// Algoritmo greedy usando estructuras repetitivas anidadas
int OptimizadorGreedy::optimizar(Movimiento resultado[]) {
    totalMovimientos = 0;
    costoTotal = 0;
    
    // Bucles anidados para recorrer productos y almacenes
    for (int producto = 0; producto < NUM_PRODUCTOS; ++producto) {
        for (int destino = 0; destino < NUM_ALMACENES; ++destino) {
            int faltante = umbrales[producto] - stock[destino][producto];
            
            // Estructura repetitiva while con condicionales anidadas
            while (faltante > 0 && totalMovimientos < MAX_MOVIMIENTOS) {
                int origen = encontrarMejorOrigen(producto, destino);
                if (origen == -1) break;
                
                int disponible = stock[origen][producto] - umbrales[producto];
                if (disponible <= 0) break;
                
                // Calcular cantidad mínima sin usar std::min
                int cantidad = (faltante < disponible) ? faltante : disponible;
                realizarMovimiento(producto, origen, destino, cantidad, totalMovimientos);
                faltante -= cantidad;
                totalMovimientos++;
            }
        }
    }
    
    // Copiar movimientos al arreglo resultado
    for (int i = 0; i < totalMovimientos; i++) {
        resultado[i] = movimientos[i];
    }
    
    return totalMovimientos;
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

// Realiza movimiento actualizando matrices y registrando en arreglo
void OptimizadorGreedy::realizarMovimiento(int producto, int origen, int destino, int cantidad, int indice) {
    // Actualizar matriz de stock
    stock[origen][producto] -= cantidad;
    stock[destino][producto] += cantidad;
    
    // Calcular costo usando matriz de distancias
    int costo = cantidad * distancias[origen][destino];
    costoTotal += costo;
    
    // Registrar movimiento en arreglo estático
    movimientos[indice] = Movimiento(producto, origen, destino, cantidad, costo);
}