#include "../include/RedistribucionService.h"
#include <iostream>
#include <iomanip>

RedistribucionService::RedistribucionService(std::unique_ptr<IOptimizador> opt)
    : optimizador(std::move(opt)) {}

void RedistribucionService::ejecutarOptimizacion() {
    auto movimientos = optimizador->optimizar();
    
    if (movimientos.empty()) {
        std::cout << "✅ No se requieren movimientos de redistribución\n";
        return;
    }
    
    std::cout << "\n=== RESULTADOS DE REDISTRIBUCIÓN ===\n";
    for (const auto& mov : movimientos) {
        std::cout << "Producto " << mov.producto << ": " << mov.cantidad
                  << " unidades movidas de Almacén " << mov.origen
                  << " a Almacén " << mov.destino
                  << ". Costo: " << mov.costo << std::endl;
    }
    
    std::cout << "Total de movimientos realizados: " << movimientos.size() << std::endl;
    std::cout << "Costo total: " << optimizador->obtenerCostoTotal() << std::endl;
}

void RedistribucionService::mostrarResultados() const {
    std::cout << "\n📊 Optimización completada\n";
    std::cout << "💰 Costo total: " << optimizador->obtenerCostoTotal() << std::endl;
}

void RedistribucionService::cargarDatosPrueba() {
    // Stock inicial
    std::array<std::array<int, 15>, 6> stockPrueba = {};
    stockPrueba[0][7] = 25;  // Almacén 0, Producto 7: exceso
    stockPrueba[3][7] = 2;   // Almacén 3, Producto 7: déficit
    stockPrueba[5][12] = 20; // Almacén 5, Producto 12: exceso
    stockPrueba[2][12] = 3;  // Almacén 2, Producto 12: déficit
    
    // Distancias
    std::array<std::array<int, 6>, 6> distanciasPrueba = {};
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            distanciasPrueba[i][j] = (i == j) ? 0 : 1;
        }
    }
    distanciasPrueba[0][3] = 7;
    distanciasPrueba[5][2] = 5;
    
    // Umbrales
    std::array<int, 15> umbralesPrueba = {};
    umbralesPrueba.fill(5);
    umbralesPrueba[7] = 10;
    umbralesPrueba[12] = 8;
    
    optimizador->configurarStock(stockPrueba);
    optimizador->configurarDistancias(distanciasPrueba);
    optimizador->configurarUmbrales(umbralesPrueba);
    
    std::cout << "✅ Datos de prueba cargados exitosamente\n";
}

void RedistribucionService::configurarMatrices() {
    std::array<std::array<int, 15>, 6> stock = {};
    std::array<std::array<int, 6>, 6> distancias = {};
    std::array<int, 15> umbrales = {};
    
    std::cout << "Configurando stock (ingrese 0 para omitir):\n";
    for (int a = 0; a < 6; ++a) {
        for (int p = 0; p < 15; ++p) {
            std::cout << "Stock[" << a << "][" << p << "]: ";
            std::cin >> stock[a][p];
        }
    }
    
    std::cout << "Configurando distancias:\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i != j) {
                std::cout << "Distancia[" << i << "][" << j << "]: ";
                std::cin >> distancias[i][j];
            }
        }
    }
    
    std::cout << "Configurando umbrales:\n";
    for (int p = 0; p < 15; ++p) {
        std::cout << "Umbral producto " << p << ": ";
        std::cin >> umbrales[p];
    }
    
    optimizador->configurarStock(stock);
    optimizador->configurarDistancias(distancias);
    optimizador->configurarUmbrales(umbrales);
}