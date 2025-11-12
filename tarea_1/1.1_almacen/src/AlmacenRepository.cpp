#include "../include/AlmacenRepository.h"
#include "../include/ComponenteNacional.h"
#include "../include/ComponenteImportado.h"
#include <cstring>

using namespace std;

// Constructor: inicializa el arreglo estático
AlmacenRepository::AlmacenRepository() : totalComponentes(0) {
  // Inicializar arreglo con punteros nulos
  for (int i = 0; i < MAX_COMPONENTES; i++) {
    componentes[i] = nullptr;
  }
}

// Destructor: libera memoria de componentes
AlmacenRepository::~AlmacenRepository() {
  for (int i = 0; i < totalComponentes; i++) {
    delete componentes[i];
  }
}

// Busca el índice de un componente por código usando búsqueda lineal
int AlmacenRepository::buscarIndice(const string &codigo) {
  for (int i = 0; i < totalComponentes; i++) {
    if (componentes[i] && componentes[i]->getCodigo() == codigo) {
      return i;
    }
  }
  return -1; // No encontrado
}

// Ordena componentes por código usando algoritmo burbuja
void AlmacenRepository::ordenarPorCodigo() {
  for (int i = 0; i < totalComponentes - 1; i++) {
    for (int j = 0; j < totalComponentes - i - 1; j++) {
      if (componentes[j]->getCodigo() > componentes[j + 1]->getCodigo()) {
        // Intercambiar elementos
        IComponente* temp = componentes[j];
        componentes[j] = componentes[j + 1];
        componentes[j + 1] = temp;
      }
    }
  }
}

// Agrega un componente al arreglo estático
bool AlmacenRepository::agregar(IComponente* componente) {
  if (!componente || totalComponentes >= MAX_COMPONENTES) {
    return false;
  }
  
  // Verificar duplicados
  if (buscarIndice(componente->getCodigo()) != -1) {
    return false;
  }
  
  // Agregar al final del arreglo
  componentes[totalComponentes] = componente;
  totalComponentes++;
  ordenarPorCodigo(); // Mantener ordenado
  return true;
}

// Busca un componente por código
IComponente* AlmacenRepository::buscar(const string &codigo) {
  int indice = buscarIndice(codigo);
  return (indice != -1) ? componentes[indice] : nullptr;
}

// Filtra componentes nacionales por precio mínimo
int AlmacenRepository::filtrarNacionales(IComponente* resultado[], double precioMinimo) {
  int count = 0;
  for (int i = 0; i < totalComponentes && count < MAX_COMPONENTES; i++) {
    if (componentes[i] && componentes[i]->getTipo() == "Nacional" && 
        componentes[i]->calcularPrecioVenta() >= precioMinimo) {
      resultado[count] = componentes[i];
      count++;
    }
  }
  return count;
}

// Filtra componentes importados por país
int AlmacenRepository::filtrarImportados(IComponente* resultado[], const string &pais) {
  int count = 0;
  for (int i = 0; i < totalComponentes && count < MAX_COMPONENTES; i++) {
    if (componentes[i] && componentes[i]->getTipo() == "Importado") {
      ComponenteImportado* importado = static_cast<ComponenteImportado*>(componentes[i]);
      if (importado->getPais() == pais) {
        resultado[count] = componentes[i];
        count++;
      }
    }
  }
  return count;
}

// Filtra componentes con stock bajo
int AlmacenRepository::filtrarBajoStock(IComponente* resultado[]) {
  int count = 0;
  for (int i = 0; i < totalComponentes && count < MAX_COMPONENTES; i++) {
    if (componentes[i] && componentes[i]->esBajoStock()) {
      resultado[count] = componentes[i];
      count++;
    }
  }
  return count;
}

// Actualiza la cantidad de un componente
bool AlmacenRepository::actualizar(const string &codigo, int nuevaCantidad) {
  IComponente* componente = buscar(codigo);
  if (!componente) return false;
  
  componente->setCantidad(nuevaCantidad);
  return true;
}
