#pragma once
#include "ComponenteBase.h"

using namespace std;

// Clase que representa un componente electrónico importado
// Hereda de ComponenteBase e incluye cálculo con precio en USD
class ComponenteImportado : public ComponenteBase {
private:
  string paisProcedencia;  // País de origen del componente
  double precioUSD;        // Precio adicional en dólares
  static constexpr double MARGEN = 0.05;    // Margen de ganancia del 5%
  static constexpr double FACTOR_USD = 27.0; // Factor de conversión USD a pesos

public:
  // Constructor que inicializa un componente importado con todos sus datos
  ComponenteImportado(const string &codigo, const string &nombre,
                      double precioCosto, int cantidad, const string &pais,
                      double precioUSD, int nivelMinimo = 10);

  // Calcula precio de venta aplicando margen y conversión USD
  double calcularPrecioVenta() const override;
  // Retorna el tipo de componente
  string getTipo() const override { return "Importado"; }
  // Getter para obtener el país de procedencia
  string getPais() const { return paisProcedencia; }
};
