#include "../include/AlmacenService.h"
#include "../include/ComponenteNacional.h"
#include "../include/ComponenteImportado.h"
#include <memory>
#include <stdexcept>

using namespace std;

// Constructor: Inyección de dependencia del repositorio
AlmacenService::AlmacenService(unique_ptr<IAlmacenRepository> repo) 
    : repository(move(repo)) {}

// Registra componente nacional usando factory pattern
void AlmacenService::registrarNacional(const string& codigo, const string& nombre,
                                      double precio, int cantidad, const string& empresa, int minimo) {
    auto componente = make_unique<ComponenteNacional>(codigo, nombre, precio, cantidad, empresa, minimo);
    repository->agregar(move(componente));
}

// Registra componente importado con precio en USD
void AlmacenService::registrarImportado(const string& codigo, const string& nombre,
                                       double precio, int cantidad, const string& pais, 
                                       double precioUSD, int minimo) {
    auto componente = make_unique<ComponenteImportado>(codigo, nombre, precio, cantidad, pais, precioUSD, minimo);
    repository->agregar(move(componente));
}

// Modifica cantidad en stock usando lambda para actualización
void AlmacenService::modificarCantidad(const string& codigo, int cantidad) {
    if (!repository->actualizar(codigo, [cantidad](IComponente* c) { c->setCantidad(cantidad); }))
        throw runtime_error("Componente no encontrado: " + codigo);
}

// Actualiza umbral mínimo de inventario
void AlmacenService::modificarNivelMinimo(const string& codigo, int nivel) {
    if (!repository->actualizar(codigo, [nivel](IComponente* c) { c->setNivelMinimo(nivel); }))
        throw runtime_error("Componente no encontrado: " + codigo);
}

// Filtra componentes nacionales con precio superior al mínimo
vector<IComponente*> AlmacenService::nacionalesPorPrecio(double minimo) {
    return repository->filtrar([minimo](const IComponente* c) {
        return c->getTipo() == "Nacional" && c->calcularPrecioVenta() > minimo;
    });
}

// Filtra componentes importados por país de procedencia
vector<IComponente*> AlmacenService::importadosPorPais(const string& pais) {
    return repository->filtrar([&pais](const IComponente* c) {
        if (c->getTipo() != "Importado") return false;
        auto* importado = static_cast<const ComponenteImportado*>(c);
        return importado->getPais() == pais;
    });
}

// Identifica componentes con stock por debajo del umbral mínimo
vector<IComponente*> AlmacenService::componentesBajoStock() {
    return repository->filtrar([](const IComponente* c) { return c->esBajoStock(); });
}