#pragma once
#include "ComponenteBase.h"

class ComponenteImportado : public ComponenteBase {
private:
    std::string paisProcedencia;
    double precioUSD;
    static constexpr double MARGEN = 0.05;
    static constexpr double FACTOR_USD = 27.0;

public:
    ComponenteImportado(const std::string& codigo, const std::string& nombre,
                        double precioCosto, int cantidad, const std::string& pais,
                        double precioUSD, int nivelMinimo = 10);
    
    double calcularPrecioVenta() const override;
    std::string getTipo() const override { return "Importado"; }
    std::string getPais() const { return paisProcedencia; }
};