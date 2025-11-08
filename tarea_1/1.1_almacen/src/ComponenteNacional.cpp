#include "../include/ComponenteNacional.h"
#include <stdexcept>

using namespace std;

// Constructor que inicializa un componente nacional con validación específica
ComponenteNacional::ComponenteNacional(const string& codigo, const string& nombre,
                                       double precioCosto, int cantidad, 
                                       const string& empresa, int nivelMinimo)
    : ComponenteBase(codigo, nombre, precioCosto, cantidad, nivelMinimo),
      empresaProductora(empresa) {
    // Validar que la empresa productora no esté vacía
    if (empresa.empty()) throw invalid_argument("Empresa requerida");
}

// Calcula el precio de venta aplicando el margen nacional del 5%
// Fórmula: precio_costo * (1 + margen)
double ComponenteNacional::calcularPrecioVenta() const {
    return precioCosto * (1.0 + MARGEN);
}