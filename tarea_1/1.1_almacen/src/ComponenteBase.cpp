#include "../include/ComponenteBase.h"
#include <stdexcept>

ComponenteBase::ComponenteBase(const std::string& codigo, const std::string& nombre,
                               double precioCosto, int cantidad, int nivelMinimo)
    : codigo(codigo), nombre(nombre), precioCosto(precioCosto), 
      cantidad(cantidad), nivelMinimo(nivelMinimo) {
    validar();
}

void ComponenteBase::validar() const {
    if (codigo.empty() || nombre.empty()) 
        throw std::invalid_argument("Código y nombre requeridos");
    if (precioCosto < 0 || cantidad < 0 || nivelMinimo < 0)
        throw std::invalid_argument("Valores no pueden ser negativos");
}

void ComponenteBase::setCantidad(int nuevaCantidad) {
    if (nuevaCantidad < 0) throw std::invalid_argument("Cantidad inválida");
    cantidad = nuevaCantidad;
}

void ComponenteBase::setNivelMinimo(int nuevoNivel) {
    if (nuevoNivel < 0) throw std::invalid_argument("Nivel mínimo inválido");
    nivelMinimo = nuevoNivel;
}