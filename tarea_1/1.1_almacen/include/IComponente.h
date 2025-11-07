#pragma once
#include <string>

class IComponente {
public:
    virtual ~IComponente() = default;
    virtual std::string getCodigo() const = 0;
    virtual std::string getNombre() const = 0;
    virtual double getPrecioCosto() const = 0;
    virtual int getCantidad() const = 0;
    virtual int getNivelMinimo() const = 0;
    virtual double calcularPrecioVenta() const = 0;
    virtual std::string getTipo() const = 0;
    virtual void setCantidad(int cantidad) = 0;
    virtual void setNivelMinimo(int nivel) = 0;
    virtual bool esBajoStock() const = 0;
};