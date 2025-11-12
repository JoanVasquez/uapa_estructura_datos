#include "../include/RedistribucionService.h"
#include <iostream>
#include <iomanip>

using namespace std;

RedistribucionService::RedistribucionService(unique_ptr<IOptimizador> opt)
    : optimizador(move(opt)) {}

void RedistribucionService::ejecutarOptimizacion() {
    Movimiento movimientos[IOptimizador::MAX_MOVIMIENTOS];
    int totalMovimientos = optimizador->optimizar(movimientos);
    
    if (totalMovimientos == 0) {
        cout << "✅ No se requieren movimientos de redistribución\n";
        return;
    }
    
    cout << "\n=== RESULTADOS DE REDISTRIBUCIÓN ===\n";
    for (int i = 0; i < totalMovimientos; i++) {
        Movimiento& mov = movimientos[i];
        cout << "Producto " << mov.producto << ": " << mov.cantidad
                  << " unidades movidas de Almacén " << mov.origen
                  << " a Almacén " << mov.destino
                  << ". Costo: " << mov.costo << endl;
    }
    
    cout << "Total de movimientos realizados: " << totalMovimientos << endl;
    cout << "Costo total: " << optimizador->obtenerCostoTotal() << endl;
}

void RedistribucionService::mostrarResultados() const {
    cout << "\n📊 Optimización completada\n";
    cout << "💰 Costo total: " << optimizador->obtenerCostoTotal() << endl;
}

void RedistribucionService::cargarDatosPrueba() {
    // Matrices estáticas inicializadas con ceros
    int stockPrueba[6][15] = {};
    int distanciasPrueba[6][6] = {};
    int umbralesPrueba[15] = {};
    
    // Configurar stock inicial usando índices directos
    stockPrueba[0][7] = 25;  // Almacén 0, Producto 7: exceso
    stockPrueba[3][7] = 2;   // Almacén 3, Producto 7: déficit
    stockPrueba[5][12] = 20; // Almacén 5, Producto 12: exceso
    stockPrueba[2][12] = 3;  // Almacén 2, Producto 12: déficit
    
    // Configurar matriz de distancias con bucles anidados
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            distanciasPrueba[i][j] = (i == j) ? 0 : 1;
        }
    }
    distanciasPrueba[0][3] = 7;
    distanciasPrueba[5][2] = 5;
    
    // Configurar umbrales con bucle tradicional
    for (int i = 0; i < 15; i++) {
        umbralesPrueba[i] = 5;
    }
    umbralesPrueba[7] = 10;
    umbralesPrueba[12] = 8;
    
    optimizador->configurarStock(stockPrueba);
    optimizador->configurarDistancias(distanciasPrueba);
    optimizador->configurarUmbrales(umbralesPrueba);
    
    cout << "✅ Datos de prueba cargados exitosamente\n";
}

void RedistribucionService::configurarMatrices() {
    int stock[6][15] = {};
    int distancias[6][6] = {};
    int umbrales[15] = {};
    
    cout << "Configurando matriz de stock (6x15):\n";
    for (int a = 0; a < 6; ++a) {
        for (int p = 0; p < 15; ++p) {
            cout << "Stock[" << a << "][" << p << "]: ";
            cin >> stock[a][p];
        }
    }
    
    cout << "Configurando matriz de distancias (6x6):\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (i != j) {
                cout << "Distancia[" << i << "][" << j << "]: ";
                cin >> distancias[i][j];
            }
        }
    }
    
    cout << "Configurando arreglo de umbrales:\n";
    for (int p = 0; p < 15; ++p) {
        cout << "Umbral producto " << p << ": ";
        cin >> umbrales[p];
    }
    
    optimizador->configurarStock(stock);
    optimizador->configurarDistancias(distancias);
    optimizador->configurarUmbrales(umbrales);
}