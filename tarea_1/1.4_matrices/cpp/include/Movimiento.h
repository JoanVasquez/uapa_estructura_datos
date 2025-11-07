#pragma once

struct Movimiento {
    int producto;
    int origen;
    int destino;
    int cantidad;
    int costo;
    
    Movimiento(int p, int o, int d, int c, int cost)
        : producto(p), origen(o), destino(d), cantidad(c), costo(cost) {}
};