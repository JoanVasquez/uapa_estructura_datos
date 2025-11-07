#include "../include/Almacen.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <algorithm>

Almacen::Almacen() : umbralMinimo(UMBRAL_DEFAULT) {
    for (auto& almacen : stock) {
        almacen.fill(0);
    }
}

void Almacen::validarIndices(int almacen, int producto) const {
    if (almacen < 0 || almacen >= NUM_ALMACENES) {
        throw std::out_of_range("Almacén debe estar entre 0 y " + std::to_string(NUM_ALMACENES - 1));
    }
    if (producto < 0 || producto >= NUM_PRODUCTOS) {
        throw std::out_of_range("Producto debe estar entre 0 y " + std::to_string(NUM_PRODUCTOS - 1));
    }
}

void Almacen::validarAlmacen(int almacen) const {
    if (almacen < 0 || almacen >= NUM_ALMACENES) {
        throw std::out_of_range("Almacén debe estar entre 0 y " + std::to_string(NUM_ALMACENES - 1));
    }
}

void Almacen::registrarStock(int almacen, int producto, int cantidad) {
    validarIndices(almacen, producto);
    if (cantidad < 0) {
        throw std::invalid_argument("La cantidad no puede ser negativa");
    }
    stock[almacen][producto] = cantidad;
}

int Almacen::obtenerStock(int almacen, int producto) const {
    validarIndices(almacen, producto);
    return stock[almacen][producto];
}

std::vector<int> Almacen::detectarAgotados(int almacen) const {
    validarAlmacen(almacen);
    std::vector<int> agotados;
    
    for (int producto = 0; producto < NUM_PRODUCTOS; ++producto) {
        if (stock[almacen][producto] == 0) {
            agotados.push_back(producto);
        }
    }
    
    return agotados;
}

int Almacen::almacenMenorStock() const {
    int menorStock = calcularStockTotal(0);
    int almacenMenor = 0;
    
    for (int almacen = 1; almacen < NUM_ALMACENES; ++almacen) {
        int stockActual = calcularStockTotal(almacen);
        if (stockActual < menorStock) {
            menorStock = stockActual;
            almacenMenor = almacen;
        }
    }
    
    return almacenMenor;
}

std::vector<AlertaStock> Almacen::generarAlertas() const {
    std::vector<AlertaStock> alertas;
    
    for (int almacen = 0; almacen < NUM_ALMACENES; ++almacen) {
        for (int producto = 0; producto < NUM_PRODUCTOS; ++producto) {
            int stockActual = stock[almacen][producto];
            if (stockActual > 0 && stockActual < umbralMinimo) {
                alertas.push_back({almacen, producto, stockActual, umbralMinimo});
            }
        }
    }
    
    return alertas;
}

void Almacen::configurarUmbral(int umbral) {
    if (umbral < 0) {
        throw std::invalid_argument("El umbral no puede ser negativo");
    }
    umbralMinimo = umbral;
}

int Almacen::calcularStockTotal(int almacen) const {
    validarAlmacen(almacen);
    int total = 0;
    for (int producto = 0; producto < NUM_PRODUCTOS; ++producto) {
        total += stock[almacen][producto];
    }
    return total;
}

void Almacen::mostrarStock() const {
    std::cout << "\n=== INVENTARIO COMPLETO ===\n";
    std::cout << "Alm\\Prod";
    for (int p = 0; p < NUM_PRODUCTOS; ++p) {
        std::cout << std::setw(4) << "P" << p;
    }
    std::cout << std::setw(8) << "Total\n";
    
    for (int a = 0; a < NUM_ALMACENES; ++a) {
        std::cout << "A" << a << "      ";
        for (int p = 0; p < NUM_PRODUCTOS; ++p) {
            std::cout << std::setw(6) << stock[a][p];
        }
        std::cout << std::setw(8) << calcularStockTotal(a) << "\n";
    }
}

void Almacen::mostrarStockAlmacen(int almacen) const {
    validarAlmacen(almacen);
    std::cout << "\n=== ALMACÉN " << almacen << " ===\n";
    for (int p = 0; p < NUM_PRODUCTOS; ++p) {
        std::cout << "Producto " << p << ": " << stock[almacen][p] << "\n";
    }
    std::cout << "Total: " << calcularStockTotal(almacen) << "\n";
}