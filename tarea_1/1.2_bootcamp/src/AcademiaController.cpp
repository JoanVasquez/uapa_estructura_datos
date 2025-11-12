#include "../include/AcademiaController.h"

using namespace std;

// Constructor con inyección de dependencia
AcademiaController::AcademiaController(AcademiaService* srv) : service(srv) {}

// Registra estudiante usando arreglo estático
bool AcademiaController::registrarEstudiante(const string& nombre, const string& matricula) {
    return service->registrarEstudiante(nombre, matricula);
}

// Registra calificaciones usando arreglo simple
bool AcademiaController::registrarCalificaciones(const string& matricula, const double notas[5]) {
    return service->registrarCalificaciones(matricula, notas);
}

// Obtiene aprobados llenando arreglo resultado
int AcademiaController::obtenerAprobados(IEstudiante* resultado[]) {
    return service->obtenerAprobados(resultado);
}

// Obtiene ordenados llenando arreglo resultado
int AcademiaController::obtenerOrdenadosPorPromedio(IEstudiante* resultado[]) {
    return service->obtenerOrdenadosPorPromedio(resultado);
}

// Obtiene todos llenando arreglo resultado
int AcademiaController::obtenerTodos(IEstudiante* resultado[]) {
    return service->obtenerTodos(resultado);
}