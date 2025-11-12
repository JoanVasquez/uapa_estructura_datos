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

// Obtiene componentes nacionales usando arreglo estático
int AlmacenController::obtenerNacionalesPorPrecio(IComponente* resultado[], double minimo) {
  return service->nacionalesPorPrecio(resultado, minimo);
}

// Filtra componentes importados usando arreglo estático
int AlmacenController::obtenerImportadosPorPais(IComponente* resultado[], const string &pais) {
  return service->importadosPorPais(resultado, pais);
}

// Identifica componentes con stock bajo usando arreglo estático
int AlmacenController::obtenerComponentesBajoStock(IComponente* resultado[]) {
  return service->componentesBajoStock(resultado);
}
