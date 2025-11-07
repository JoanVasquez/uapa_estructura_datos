#include "../include/InventarioService.h"
#include "../include/Almacen.h"
#include <iostream>
#include <stdexcept>

InventarioService::InventarioService(std::unique_ptr<IInventario> inv)
    : inventario(std::move(inv)) {}

void InventarioService::actualizarStock(int almacen, int producto, int cantidad) {
    inventario->registrarStock(almacen, producto, cantidad);
    std::cout << "Stock actualizado: Almacén " << almacen 
              << ", Producto " << producto << " = " << cantidad << "\n";
}

void InventarioService::procesarAlertas() {
    auto alertas = inventario->generarAlertas();
    
    if (alertas.empty()) {
        std::cout << "\n✅ No hay alertas de stock bajo\n";
        return;
    }
    
    std::cout << "\n⚠️  ALERTAS DE STOCK BAJO ⚠️\n";
    for (const auto& alerta : alertas) {
        std::cout << "Almacén " << alerta.almacen 
                  << ", Producto " << alerta.producto
                  << ": Stock " << alerta.stockActual 
                  << " (Mínimo: " << alerta.umbralMinimo << ")\n";
    }
}

void InventarioService::reporteAgotados() {
    std::cout << "\n=== PRODUCTOS AGOTADOS POR ALMACÉN ===\n";
    
    for (int almacen = 0; almacen < 6; ++almacen) {
        auto agotados = inventario->detectarAgotados(almacen);
        std::cout << "Almacén " << almacen << ": ";
        
        if (agotados.empty()) {
            std::cout << "Sin productos agotados";
        } else {
            for (size_t i = 0; i < agotados.size(); ++i) {
                std::cout << "P" << agotados[i];
                if (i < agotados.size() - 1) std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
}

void InventarioService::reporteStockBajo() {
    procesarAlertas();
}

void InventarioService::reporteAlmacenCritico() {
    int almacenCritico = inventario->almacenMenorStock();
    int stockMinimo = inventario->calcularStockTotal(almacenCritico);
    
    std::cout << "\n🚨 ALMACÉN CRÍTICO 🚨\n";
    std::cout << "Almacén " << almacenCritico 
              << " tiene el menor stock total: " << stockMinimo << " unidades\n";
}

void InventarioService::configurarUmbralGlobal(int umbral) {
    inventario->configurarUmbral(umbral);
    std::cout << "Umbral mínimo configurado a: " << umbral << "\n";
}

void InventarioService::mostrarInventarioCompleto() {
    auto* almacen = dynamic_cast<Almacen*>(inventario.get());
    if (almacen) {
        almacen->mostrarStock();
    }
}

void InventarioService::mostrarInventarioAlmacen(int almacen) {
    auto* almacenPtr = dynamic_cast<Almacen*>(inventario.get());
    if (almacenPtr) {
        almacenPtr->mostrarStockAlmacen(almacen);
    }
}