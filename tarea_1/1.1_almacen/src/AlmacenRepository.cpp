#include "../include/AlmacenRepository.h"
#include <stdexcept>

void AlmacenRepository::agregar(std::unique_ptr<IComponente> componente) {
    if (!componente) throw std::invalid_argument("Componente nulo");
    
    std::string codigo = componente->getCodigo();
    if (componentes.find(codigo) != componentes.end())
        throw std::runtime_error("Código duplicado: " + codigo);
    
    componentes[codigo] = std::move(componente);
}

IComponente* AlmacenRepository::buscar(const std::string& codigo) {
    auto it = componentes.find(codigo);
    return (it != componentes.end()) ? it->second.get() : nullptr;
}

std::vector<IComponente*> AlmacenRepository::filtrar(std::function<bool(const IComponente*)> pred) {
    std::vector<IComponente*> resultado;
    for (const auto& par : componentes) {
        if (pred(par.second.get())) {
            resultado.push_back(par.second.get());
        }
    }
    return resultado;
}

bool AlmacenRepository::actualizar(const std::string& codigo, std::function<void(IComponente*)> updater) {
    auto* componente = buscar(codigo);
    if (!componente) return false;
    updater(componente);
    return true;
}