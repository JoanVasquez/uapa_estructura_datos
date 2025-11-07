#pragma once
#include "IAlmacenRepository.h"
#include <unordered_map>

class AlmacenRepository : public IAlmacenRepository {
private:
    std::unordered_map<std::string, std::unique_ptr<IComponente>> componentes;

public:
    void agregar(std::unique_ptr<IComponente> componente) override;
    IComponente* buscar(const std::string& codigo) override;
    std::vector<IComponente*> filtrar(std::function<bool(const IComponente*)> pred) override;
    bool actualizar(const std::string& codigo, std::function<void(IComponente*)> updater) override;
};