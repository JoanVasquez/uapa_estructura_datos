#include "../include/Estudiante.h"
#include <stdexcept>
#include <numeric>

using namespace std;

// Constructor que inicializa un estudiante con datos básicos
Estudiante::Estudiante(const string& nombre, const string& matricula)
    : nombre(nombre), matricula(matricula), promedio(0.0), estado("Sin calificar") {
    validarDatos(); // Validar datos de entrada
    calificaciones.fill(0.0); // Inicializar todas las calificaciones en 0
}

// Valida que los datos obligatorios no estén vacíos
void Estudiante::validarDatos() const {
    if (nombre.empty() || matricula.empty()) {
        throw invalid_argument("Nombre y matrícula son requeridos");
    }
}

// Registra las 5 calificaciones del estudiante con validación
void Estudiante::registrarCalificaciones(const array<double, 5>& notas) {
    // Validar que todas las notas estén en el rango válido (0-100)
    for (double nota : notas) {
        if (nota < 0.0 || nota > 100.0) {
            throw invalid_argument("Las calificaciones deben estar entre 0 y 100");
        }
    }
    
    // Asignar las calificaciones y recalcular promedio y estado
    calificaciones = notas;
    calcularPromedio();
    determinarEstado();
}

// Calcula el promedio aritmético de las 5 calificaciones
void Estudiante::calcularPromedio() {
    promedio = accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / 5.0;
}

// Determina el estado académico basado en el promedio
void Estudiante::determinarEstado() {
    estado = estaAprobado() ? "Aprobado" : "Reprobado";
}