#include "../include/Estudiante.h"
#include <stdexcept>
#include <numeric>

using namespace std;

// Constructor que inicializa un estudiante con datos básicos
Estudiante::Estudiante(const string& nombre, const string& matricula)
    : nombre(nombre), matricula(matricula), promedio(0.0), estado("Sin calificar") {
    validarDatos(); // Validar datos de entrada
    // Inicializar arreglo estático con bucle
    for (int i = 0; i < 5; i++) {
        calificaciones[i] = 0.0;
    }
}

// Valida que los datos obligatorios no estén vacíos
void Estudiante::validarDatos() const {
    if (nombre.empty() || matricula.empty()) {
        throw invalid_argument("Nombre y matrícula son requeridos");
    }
}

// Registra las 5 calificaciones usando arreglo estático
void Estudiante::registrarCalificaciones(const double notas[5]) {
    // Validar usando bucle tradicional
    for (int i = 0; i < 5; i++) {
        if (notas[i] < 0.0 || notas[i] > 100.0) {
            throw invalid_argument("Las calificaciones deben estar entre 0 y 100");
        }
    }
    
    // Copiar calificaciones usando bucle
    for (int i = 0; i < 5; i++) {
        calificaciones[i] = notas[i];
    }
    calcularPromedio();
    determinarEstado();
}

// Calcula el promedio usando bucle tradicional
void Estudiante::calcularPromedio() {
    double suma = 0.0;
    for (int i = 0; i < 5; i++) {
        suma += calificaciones[i];
    }
    promedio = suma / 5.0;
}

// Determina el estado académico basado en el promedio
void Estudiante::determinarEstado() {
    estado = estaAprobado() ? "Aprobado" : "Reprobado";
}