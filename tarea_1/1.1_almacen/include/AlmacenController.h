#pragma once
#include "AlmacenService.h"
#include <memory>

using namespace std;

/**
 * Controller para el sistema de almacén de componentes electrónicos.
 * Implementa el patrón MVC coordinando entre UI y Service.
 * Responsabilidades: Validación de entrada, coordinación de flujo, manejo de errores.
 */
class AlmacenController {
private:
    unique_ptr<AlmacenService> service; // Servicio de negocio inyectado

public:
    explicit AlmacenController(unique_ptr<AlmacenService> srv);
    
    // Operaciones de registro de componentes
    void registrarComponenteNacional(const string& codigo, const string& nombre,
                                   double precio, int cantidad, const string& empresa, int minimo);
    void registrarComponenteImportado(const string& codigo, const string& nombre,
                                    double precio, int cantidad, const string& pais, 
                                    double precioUSD, int minimo);
    
    // Operaciones de modificación
    void modificarCantidad(const string& codigo, int cantidad);
    void modificarNivelMinimo(const string& codigo, int nivel);
    
    // Operaciones de consulta con filtros
    vector<IComponente*> obtenerNacionalesPorPrecio(double minimo);
    vector<IComponente*> obtenerImportadosPorPais(const string& pais);
    vector<IComponente*> obtenerComponentesBajoStock();
};