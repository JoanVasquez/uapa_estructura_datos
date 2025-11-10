#include "../include/RedistribucionService.h"
#include <iostream>
#include <iomanip>

using namespace std;

RedistribucionService::RedistribucionService(unique_ptr<IOptimizador> opt)
    : optimizador(move(opt)) {}

void RedistribucionService::ejecutarOptimizacion() {
    auto movimientos = optimizador->optimizar();
    
    if (movimientos.empty()) {
        cout << "✅ No se requieren movimientos de redistribución\n";
        return;
    }
    
    cout << "\n=== RESULTADOS DE REDISTRIBUCIÓN ===\n";
    for (const auto& mov : movimientos) {
        cout << "Producto " << mov.producto << ": " << mov.cantidad
                  << " unidades movidas de Almacén " << mov.origen
                  << " a Almacén " << mov.destino
                  << ". Costo: " << mov.costo << endl;
    }
    
    cout << "Total de movimientos realizados: " << movimientos.size() << endl;
    cout << "Costo total: " << optimizador->obtenerCostoTotal() << endl;
}

void RedistribucionService::mostrarResultados() const {
    cout << "\n📊 Optimización completada\n";
    cout << "💰 Costo total: " << optimizador->obtenerCostoTotal() << endl;
}

void RedistribucionService::cargarDatosPrueba() {
    // Stock inicial
    array<array<int, 15>, 6> stockPrueba = {};
    stockPrueba[0][7] = 25;  // Almacén 0, Producto 7: exceso
    stockPrueba[3][7] = 2;   // Almacén 3, Producto 7: déficit
    stockPrueba[5][12] = 20; // Almacén 5, Producto 12: exceso
    stockPrueba[2][12] = 3;  // Almacén 2, Producto 12: déficit
    
    // Distancias
    array<array<int, 6>, 6> distanciasPrueba = {};
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            distanciasPrueba[i][j] = (i == j) ? 0 : 1;
        }
    }
    distanciasPrueba[0][3] = 7;
    distanciasPrueba[5][2] = 5;
    
    // Umbrales
    array<int, 15> umbralesPrueba = {};
    umbralesPrueba.fill(5);
    umbralesPrueba[7] = 10;
    umbralesPrueba[12] = 8;
    
    optimizador->configurarStock(stockPrueba);
    optimizador->configurarDistancias(distanciasPrueba);
    optimizador->configurarUmbrales(umbralesPrueba);
    
    cout << "✅ Datos de prueba cargados exitosamente\n";
}

void RedistribucionService::configurarMatrices() {
    array<array<int, 15>, 6> stock = {};
    array<array<int, 6>, 6> distancias = {};
    array<int, 15> umbrales = {};
    
    cout << "Configurando stock (ingrese 0 para omitir):\n";
    for (int a = 0; a < 6; ++a) {
        for (int p = 0; p < 15; ++p) {
            cout << "Stock[" << a << "][" << p << "]: ";
            cin >> stock[a][p];
        }
    }
    
    cout << "Configurando distancias:\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i != j) {
                cout << "Distancia[" << i << "][" << j << "]: ";
                cin >> distancias[i][j];
            }
        }
    }
    
    cout << "Configurando umbrales:\n";
    for (int p = 0; p < 15; ++p) {
        cout << "Umbral producto " << p << ": ";
        cin >> umbrales[p];
    }
    
    optimizador->configurarStock(stock);
    optimizador->configurarDistancias(distancias);
    optimizador->configurarUmbrales(umbrales);
}