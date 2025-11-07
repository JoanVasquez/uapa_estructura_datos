#pragma once
#include "ComponenteBase.h"

class ComponenteNacional : public ComponenteBase {
private:
    std::string empresaProductora;
    static constexpr double MARGEN = 0.05;

public:
    ComponenteNacional(const std::string& codigo, const std::string& nombre,
                       double precioCosto, int cantidad, const std::string& empresa,
                       int nivelMinimo = 10);
    
    double calcularPrecioVenta() const override;
    std::string getTipo() const override { return "Nacional"; }
    std::string getEmpresa() const { return empresaProductora; }
};