#include "../include/ComponenteBase.h"
#include <stdexcept>

using namespace std;

// Constructor que inicializa todos los atributos y valida los datos
ComponenteBase::ComponenteBase(const string& codigo, const string& nombre,
                               double precioCosto, int cantidad, int nivelMinimo)
    : codigo(codigo), nombre(nombre), precioCosto(precioCosto), 
      cantidad(cantidad), nivelMinimo(nivelMinimo) {
    validar(); // Validar datos al crear el objeto
}

// Método privado que valida la integridad de los datos del componente
void ComponenteBase::validar() const {
    // Verificar que los campos obligatorios no estén vacíos
    if (codigo.empty() || nombre.empty()) 
        throw invalid_argument("Código y nombre requeridos");
    // Verificar que los valores numéricos no sean negativos
    if (precioCosto < 0 || cantidad < 0 || nivelMinimo < 0)
        throw invalid_argument("Valores no pueden ser negativos");
}

// Actualiza la cantidad en stock con validación
void ComponenteBase::setCantidad(int nuevaCantidad) {
    if (nuevaCantidad < 0) throw invalid_argument("Cantidad inválida");
    cantidad = nuevaCantidad;
}

// Actualiza el nivel mínimo de inventario con validación
void ComponenteBase::setNivelMinimo(int nuevoNivel) {
    if (nuevoNivel < 0) throw invalid_argument("Nivel mínimo inválido");
    nivelMinimo = nuevoNivel;
}