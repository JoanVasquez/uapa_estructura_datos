#pragma once
#include <string>

using namespace std;

// Interfaz que define el contrato para todos los componentes electrónicos
// Implementa el principio de Inversión de Dependencias (SOLID)
class IComponente {
public:
  virtual ~IComponente() = default; // Destructor virtual para polimorfismo
  
  // Métodos getter puros para obtener información del componente
  virtual string getCodigo() const = 0;        // Código único del componente
  virtual string getNombre() const = 0;        // Nombre descriptivo
  virtual double getPrecioCosto() const = 0;   // Precio de costo
  virtual int getCantidad() const = 0;         // Cantidad en stock
  virtual int getNivelMinimo() const = 0;      // Nivel mínimo de inventario
  
  // Métodos de negocio puros
  virtual double calcularPrecioVenta() const = 0; // Cálculo de precio de venta
  virtual string getTipo() const = 0;             // Tipo de componente
  
  // Métodos setter puros para modificar el estado
  virtual void setCantidad(int cantidad) = 0;     // Actualizar cantidad
  virtual void setNivelMinimo(int nivel) = 0;     // Actualizar nivel mínimo
  
  // Método de consulta de estado
  virtual bool esBajoStock() const = 0;           // Verificar si está bajo stock
};
