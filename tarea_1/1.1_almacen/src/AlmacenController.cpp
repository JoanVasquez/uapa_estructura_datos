#include "../include/AlmacenController.h"

using namespace std;

// Constructor: Inyección de dependencia del servicio
AlmacenController::AlmacenController(unique_ptr<AlmacenService> srv)
    : service(move(srv)) {}

// Registra componente nacional delegando al servicio
void AlmacenController::registrarComponenteNacional(const string &codigo,
                                                    const string &nombre,
                                                    double precio, int cantidad,
                                                    const string &empresa,
                                                    int minimo) {
  service->registrarNacional(codigo, nombre, precio, cantidad, empresa, minimo);
}

// Registra componente importado con precio en USD
void AlmacenController::registrarComponenteImportado(
    const string &codigo, const string &nombre, double precio,
    int cantidad, const string &pais, double precioUSD, int minimo) {
  service->registrarImportado(codigo, nombre, precio, cantidad, pais, precioUSD,
                              minimo);
}

// Actualiza cantidad en stock de un componente
void AlmacenController::modificarCantidad(const string &codigo,
                                          int cantidad) {
  service->modificarCantidad(codigo, cantidad);
}

// Modifica umbral mínimo de inventario
void AlmacenController::modificarNivelMinimo(const string &codigo,
                                             int nivel) {
  service->modificarNivelMinimo(codigo, nivel);
}

// Obtiene componentes nacionales con precio superior al mínimo
vector<IComponente *>
AlmacenController::obtenerNacionalesPorPrecio(double minimo) {
  return service->nacionalesPorPrecio(minimo);
}

// Filtra componentes importados por país de procedencia
vector<IComponente *>
AlmacenController::obtenerImportadosPorPais(const string &pais) {
  return service->importadosPorPais(pais);
}

// Identifica componentes con stock por debajo del umbral
vector<IComponente *> AlmacenController::obtenerComponentesBajoStock() {
  return service->componentesBajoStock();
}
