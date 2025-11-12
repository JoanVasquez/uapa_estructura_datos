#pragma once
#include "IComponente.h"

using namespace std;

// Interfaz del repositorio que define operaciones CRUD para componentes
// Usa arreglos estáticos para cumplir con los criterios de evaluación
class IAlmacenRepository {
public:
  static const int MAX_COMPONENTES = 100; // Tamaño máximo del arreglo
  
  virtual ~IAlmacenRepository() = default;
  virtual bool agregar(IComponente* componente) = 0;
  virtual IComponente* buscar(const string &codigo) = 0;
  virtual int filtrarNacionales(IComponente* resultado[], double precioMinimo) = 0;
  virtual int filtrarImportados(IComponente* resultado[], const string &pais) = 0;
  virtual int filtrarBajoStock(IComponente* resultado[]) = 0;
  virtual bool actualizar(const string &codigo, int nuevaCantidad) = 0;
  virtual int obtenerTotal() const = 0;
  virtual IComponente** obtenerTodos() = 0;
};
