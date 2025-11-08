#pragma once
#include "IComponente.h"

using namespace std;

// Clase base abstracta que implementa la funcionalidad común de todos los componentes
// Implementa el patrón Template Method para validación y operaciones básicas
class ComponenteBase : public IComponente {
protected:
  string codigo, nombre;    // Identificador único y nombre descriptivo
  double precioCosto;       // Precio de costo del componente
  int cantidad, nivelMinimo; // Stock actual y nivel mínimo de inventario

  // Método de validación que verifica la integridad de los datos
  void validar() const; // const method cannot modify the above attributes

public:
  // Constructor que inicializa todos los atributos comunes
  ComponenteBase(const string &codigo, const string &nombre, double precioCosto,
                 int cantidad, int nivelMinimo = 10); //& valor por referencia

  // Métodos getter que retornan los valores de los atributos
  string getCodigo() const override { return codigo; }
  string getNombre() const override { return nombre; }
  double getPrecioCosto() const override { return precioCosto; }
  int getCantidad() const override { return cantidad; }
  int getNivelMinimo() const override { return nivelMinimo; }

  // Métodos setter con validación para modificar valores
  void setCantidad(int cantidad) override;
  void setNivelMinimo(int nivel) override;

  // Determina si el componente tiene stock bajo comparando con el nivel mínimo
  bool esBajoStock() const override { return cantidad < nivelMinimo; }
};
