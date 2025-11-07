#pragma once
#include "IComponente.h"
#include <vector>
#include <memory>
#include <functional>

class IAlmacenRepository {
public:
    virtual ~IAlmacenRepository() = default;
    virtual void agregar(std::unique_ptr<IComponente> componente) = 0;
    virtual IComponente* buscar(const std::string& codigo) = 0;
    virtual std::vector<IComponente*> filtrar(std::function<bool(const IComponente*)> pred) = 0;
    virtual bool actualizar(const std::string& codigo, std::function<void(IComponente*)> updater) = 0;
};