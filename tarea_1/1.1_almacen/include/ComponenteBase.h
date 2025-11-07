#pragma once
#include "IComponente.h"

class ComponenteBase : public IComponente {
protected:
    std::string codigo, nombre;
    double precioCosto;
    int cantidad, nivelMinimo;
    
    void validar() const;

public:
    ComponenteBase(const std::string& codigo, const std::string& nombre, 
                   double precioCosto, int cantidad, int nivelMinimo = 10);
    
    std::string getCodigo() const override { return codigo; }
    std::string getNombre() const override { return nombre; }
    double getPrecioCosto() const override { return precioCosto; }
    int getCantidad() const override { return cantidad; }
    int getNivelMinimo() const override { return nivelMinimo; }
    void setCantidad(int cantidad) override;
    void setNivelMinimo(int nivel) override;
    bool esBajoStock() const override { return cantidad < nivelMinimo; }
};