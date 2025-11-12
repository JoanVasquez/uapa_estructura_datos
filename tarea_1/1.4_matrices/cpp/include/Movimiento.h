#pragma once

struct Movimiento {
    int producto;
    int origen;
    int destino;
    int cantidad;
    int costo;
    
    // Constructor por defecto
    Movimiento() : producto(0), origen(0), destino(0), cantidad(0), costo(0) {}
    
    // Constructor con parámetros
    Movimiento(int p, int o, int d, int c, int cost)
        : producto(p), origen(o), destino(d), cantidad(c), costo(cost) {}
};