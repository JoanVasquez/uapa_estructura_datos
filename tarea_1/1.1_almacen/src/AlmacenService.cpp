#include "../include/AlmacenService.h"
#include "../include/ComponenteNacional.h"
#include "../include/ComponenteImportado.h"
#include <memory>
#include <stdexcept>

AlmacenService::AlmacenService(std::unique_ptr<IAlmacenRepository> repo) 
    : repository(std::move(repo)) {}

void AlmacenService::registrarNacional(const std::string& codigo, const std::string& nombre,
                                      double precio, int cantidad, const std::string& empresa, int minimo) {
    auto componente = std::make_unique<ComponenteNacional>(codigo, nombre, precio, cantidad, empresa, minimo);
    repository->agregar(std::move(componente));
}

void AlmacenService::registrarImportado(const std::string& codigo, const std::string& nombre,
                                       double precio, int cantidad, const std::string& pais, 
                                       double precioUSD, int minimo) {
    auto componente = std::make_unique<ComponenteImportado>(codigo, nombre, precio, cantidad, pais, precioUSD, minimo);
    repository->agregar(std::move(componente));
}

void AlmacenService::modificarCantidad(const std::string& codigo, int cantidad) {
    if (!repository->actualizar(codigo, [cantidad](IComponente* c) { c->setCantidad(cantidad); }))
        throw std::runtime_error("Componente no encontrado: " + codigo);
}

void AlmacenService::modificarNivelMinimo(const std::string& codigo, int nivel) {
    if (!repository->actualizar(codigo, [nivel](IComponente* c) { c->setNivelMinimo(nivel); }))
        throw std::runtime_error("Componente no encontrado: " + codigo);
}

std::vector<IComponente*> AlmacenService::nacionalesPorPrecio(double minimo) {
    return repository->filtrar([minimo](const IComponente* c) {
        return c->getTipo() == "Nacional" && c->calcularPrecioVenta() > minimo;
    });
}

std::vector<IComponente*> AlmacenService::importadosPorPais(const std::string& pais) {
    return repository->filtrar([&pais](const IComponente* c) {
        if (c->getTipo() != "Importado") return false;
        auto* importado = static_cast<const ComponenteImportado*>(c);
        return importado->getPais() == pais;
    });
}

std::vector<IComponente*> AlmacenService::componentesBajoStock() {
    return repository->filtrar([](const IComponente* c) { return c->esBajoStock(); });
}