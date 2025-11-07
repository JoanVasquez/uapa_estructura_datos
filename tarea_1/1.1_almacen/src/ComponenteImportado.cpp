#include "../include/ComponenteImportado.h"
#include <stdexcept>

ComponenteImportado::ComponenteImportado(const std::string& codigo, const std::string& nombre,
                                         double precioCosto, int cantidad, 
                                         const std::string& pais, double precioUSD, int nivelMinimo)
    : ComponenteBase(codigo, nombre, precioCosto, cantidad, nivelMinimo),
      paisProcedencia(pais), precioUSD(precioUSD) {
    if (pais.empty()) throw std::invalid_argument("País requerido");
    if (precioUSD < 0) throw std::invalid_argument("Precio USD inválido");
}

double ComponenteImportado::calcularPrecioVenta() const {
    return precioCosto * (1.0 + MARGEN) + (FACTOR_USD * precioUSD);
}