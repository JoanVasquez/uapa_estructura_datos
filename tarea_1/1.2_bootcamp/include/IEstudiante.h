#pragma once
#include <string>
#include <array>

class IEstudiante {
public:
    virtual ~IEstudiante() = default;
    virtual std::string getNombre() const = 0;
    virtual std::string getMatricula() const = 0;
    virtual double getPromedio() const = 0;
    virtual std::string getEstado() const = 0;
    virtual void registrarCalificaciones(const std::array<double, 5>& notas) = 0;
    virtual bool estaAprobado() const = 0;
};