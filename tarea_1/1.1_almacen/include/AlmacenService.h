#pragma once
#include "IAlmacenRepository.h"

using namespace std;

// Servicio de lógica de negocio para el almacén de componentes
// Maneja arreglos estáticos y operaciones de negocio
class AlmacenService {
private:
  IAlmacenRepository* repository; // Repositorio inyectado
  
public:
  explicit AlmacenService(IAlmacenRepository* repo);

  // Casos de uso de registro con validación
  bool registrarNacional(const string &codigo, const string &nombre,
                         double precio, int cantidad, const string &empresa,
                         int minimo = 10);
  bool registrarImportado(const string &codigo, const string &nombre,
                          double precio, int cantidad, const string &pais,
                          double precioUSD, int minimo = 10);

  // Casos de uso de modificación
  bool modificarCantidad(const string &codigo, int cantidad);
  bool modificarNivelMinimo(const string &codigo, int nivel);

  // Casos de uso de consulta que llenan arreglos estáticos
  int nacionalesPorPrecio(IComponente* resultado[], double minimo);
  int importadosPorPais(IComponente* resultado[], const string &pais);
  int componentesBajoStock(IComponente* resultado[]);
  
  // Obtener todos los componentes
  IComponente** obtenerTodos() { return repository->obtenerTodos(); }
  int obtenerTotal() { return repository->obtenerTotal(); }
};
