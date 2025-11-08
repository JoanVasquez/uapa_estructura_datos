#pragma once
#include "ComponenteBase.h"

using namespace std;

// Clase que representa un componente electrónico de fabricación nacional
// Hereda de ComponenteBase e implementa cálculo específico de precio de venta
class ComponenteNacional : public ComponenteBase {
private:
  string empresaProductora;  // Empresa que fabrica el componente
  static constexpr double MARGEN = 0.05;  // Margen de ganancia del 5%

public:
  // Constructor que inicializa un componente nacional con todos sus datos
  ComponenteNacional(const string &codigo, const string &nombre,
                     double precioCosto, int cantidad,
                     const string &empresa, int nivelMinimo = 10);

  // Calcula precio de venta aplicando margen nacional
  double calcularPrecioVenta() const override;
  // Retorna el tipo de componente
  string getTipo() const override { return "Nacional"; }
  // Getter para obtener la empresa productora
  string getEmpresa() const { return empresaProductora; }
};
