#pragma once
#include "IAlmacenRepository.h"

using namespace std;

// Implementación del repositorio usando arreglo estático
// Maneja componentes electrónicos con operaciones básicas de arreglos
class AlmacenRepository : public IAlmacenRepository {
private:
  IComponente* componentes[MAX_COMPONENTES]; // Arreglo estático de componentes
  int totalComponentes; // Contador de componentes actuales
  
  // Funciones auxiliares para manipulación de arreglos
  int buscarIndice(const string &codigo);
  void ordenarPorCodigo(); // Ordenamiento burbuja

public:
  AlmacenRepository();
  ~AlmacenRepository();
  
  bool agregar(IComponente* componente) override;
  IComponente* buscar(const string &codigo) override;
  int filtrarNacionales(IComponente* resultado[], double precioMinimo) override;
  int filtrarImportados(IComponente* resultado[], const string &pais) override;
  int filtrarBajoStock(IComponente* resultado[]) override;
  bool actualizar(const string &codigo, int nuevaCantidad) override;
  int obtenerTotal() const override { return totalComponentes; }
  IComponente** obtenerTodos() override { return componentes; }
};
