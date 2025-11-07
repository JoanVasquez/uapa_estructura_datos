#include "../include/Estudiante.h"
#include <stdexcept>
#include <numeric>

Estudiante::Estudiante(const std::string& nombre, const std::string& matricula)
    : nombre(nombre), matricula(matricula), promedio(0.0), estado("Sin calificar") {
    validarDatos();
    calificaciones.fill(0.0);
}

void Estudiante::validarDatos() const {
    if (nombre.empty() || matricula.empty()) {
        throw std::invalid_argument("Nombre y matrícula son requeridos");
    }
}

void Estudiante::registrarCalificaciones(const std::array<double, 5>& notas) {
    for (double nota : notas) {
        if (nota < 0.0 || nota > 100.0) {
            throw std::invalid_argument("Las calificaciones deben estar entre 0 y 100");
        }
    }
    
    calificaciones = notas;
    calcularPromedio();
    determinarEstado();
}

void Estudiante::calcularPromedio() {
    promedio = std::accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / 5.0;
}

void Estudiante::determinarEstado() {
    estado = estaAprobado() ? "Aprobado" : "Reprobado";
}