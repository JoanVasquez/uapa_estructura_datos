#pragma once
#include "IEstudiante.h"
#include <vector>
#include <memory>
#include <functional>

class IAcademiaRepository {
public:
    virtual ~IAcademiaRepository() = default;
    virtual void agregar(std::unique_ptr<IEstudiante> estudiante) = 0;
    virtual IEstudiante* buscar(const std::string& matricula) = 0;
    virtual std::vector<IEstudiante*> obtenerTodos() = 0;
    virtual std::vector<IEstudiante*> filtrar(std::function<bool(const IEstudiante*)> pred) = 0;
    virtual void ordenar(std::function<bool(const IEstudiante*, const IEstudiante*)> comp) = 0;
    virtual size_t obtenerCantidad() const = 0;
};