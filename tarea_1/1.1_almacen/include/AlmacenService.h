#pragma once
#include "IAlmacenRepository.h"
#include <memory>

using namespace std;

/**
 * Servicio de lógica de negocio para el almacén de componentes.
 * Implementa casos de uso y reglas de negocio.
 * Coordina entre controller y repository.
 */
class AlmacenService {
private:
  unique_ptr<IAlmacenRepository> repository; // Repositorio inyectado

public:
  explicit AlmacenService(unique_ptr<IAlmacenRepository> repo);

  // Casos de uso de registro
  void registrarNacional(const string &codigo, const string &nombre,
                         double precio, int cantidad, const string &empresa,
                         int minimo = 10);
  void registrarImportado(const string &codigo, const string &nombre,
                          double precio, int cantidad, const string &pais,
                          double precioUSD, int minimo = 10);

  // Casos de uso de modificación
  void modificarCantidad(const string &codigo, int cantidad);
  void modificarNivelMinimo(const string &codigo, int nivel);

  // Casos de uso de consulta con lógica de negocio
  vector<IComponente *> nacionalesPorPrecio(double minimo);
  vector<IComponente *> importadosPorPais(const string &pais);
  vector<IComponente *> componentesBajoStock();
};
