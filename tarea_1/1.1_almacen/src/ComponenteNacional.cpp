#include "../include/ComponenteNacional.h"
#include <stdexcept>

ComponenteNacional::ComponenteNacional(const std::string& codigo, const std::string& nombre,
                                       double precioCosto, int cantidad, 
                                       const std::string& empresa, int nivelMinimo)
    : ComponenteBase(codigo, nombre, precioCosto, cantidad, nivelMinimo),
      empresaProductora(empresa) {
    if (empresa.empty()) throw std::invalid_argument("Empresa requerida");
}

double ComponenteNacional::calcularPrecioVenta() const {
    return precioCosto * (1.0 + MARGEN);
}