#include "../include/AlmacenService.h"
#include "../include/ComponenteNacional.h"
#include "../include/ComponenteImportado.h"

using namespace std;

// Constructor: Inyección de dependencia del repositorio
AlmacenService::AlmacenService(IAlmacenRepository* repo) : repository(repo) {}

// Registra componente nacional creando objeto dinámicamente
bool AlmacenService::registrarNacional(const string& codigo, const string& nombre,
                                      double precio, int cantidad, const string& empresa, int minimo) {
    ComponenteNacional* componente = new ComponenteNacional(codigo, nombre, precio, cantidad, empresa, minimo);
    return repository->agregar(componente);
}

// Registra componente importado con precio en USD
bool AlmacenService::registrarImportado(const string& codigo, const string& nombre,
                                       double precio, int cantidad, const string& pais, 
                                       double precioUSD, int minimo) {
    ComponenteImportado* componente = new ComponenteImportado(codigo, nombre, precio, cantidad, pais, precioUSD, minimo);
    return repository->agregar(componente);
}

// Modifica cantidad en stock
bool AlmacenService::modificarCantidad(const string& codigo, int cantidad) {
    return repository->actualizar(codigo, cantidad);
}

// Actualiza umbral mínimo de inventario
bool AlmacenService::modificarNivelMinimo(const string& codigo, int nivel) {
    IComponente* componente = repository->buscar(codigo);
    if (!componente) return false;
    
    componente->setNivelMinimo(nivel);
    return true;
}

// Filtra componentes nacionales con precio superior al mínimo
int AlmacenService::nacionalesPorPrecio(IComponente* resultado[], double minimo) {
    return repository->filtrarNacionales(resultado, minimo);
}

// Filtra componentes importados por país de procedencia
int AlmacenService::importadosPorPais(IComponente* resultado[], const string& pais) {
    return repository->filtrarImportados(resultado, pais);
}

// Identifica componentes con stock por debajo del umbral mínimo
int AlmacenService::componentesBajoStock(IComponente* resultado[]) {
    return repository->filtrarBajoStock(resultado);
}