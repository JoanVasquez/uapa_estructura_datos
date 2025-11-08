#include "../include/ComponenteImportado.h"
#include <stdexcept>

using namespace std;

// Constructor que inicializa un componente importado con validaciones específicas
ComponenteImportado::ComponenteImportado(const string& codigo, const string& nombre,
                                         double precioCosto, int cantidad, 
                                         const string& pais, double precioUSD, int nivelMinimo)
    : ComponenteBase(codigo, nombre, precioCosto, cantidad, nivelMinimo),
      paisProcedencia(pais), precioUSD(precioUSD) {
    // Validar que el país de procedencia no esté vacío
    if (pais.empty()) throw invalid_argument("País requerido");
    // Validar que el precio en USD no sea negativo
    if (precioUSD < 0) throw invalid_argument("Precio USD inválido");
}

// Calcula el precio de venta aplicando margen del 5% más conversión de USD
// Fórmula: (precio_costo * (1 + margen)) + (factor_usd * precio_usd)
double ComponenteImportado::calcularPrecioVenta() const {
    return precioCosto * (1.0 + MARGEN) + (FACTOR_USD * precioUSD);
}