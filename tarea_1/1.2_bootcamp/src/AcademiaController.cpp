#include "../include/AcademiaController.h"

using namespace std;

// Constructor: Inyección de dependencia del servicio académico
AcademiaController::AcademiaController(unique_ptr<AcademiaService> srv)
    : service(move(srv)) {}

// Registra nuevo estudiante en el sistema
void AcademiaController::registrarEstudiante(const string& nombre, const string& matricula) {
    service->registrarEstudiante(nombre, matricula);
}

// Registra las 5 calificaciones de un estudiante y calcula promedio
void AcademiaController::registrarCalificaciones(const string& matricula, const array<double, 5>& notas) {
    service->registrarCalificaciones(matricula, notas);
}

// Obtiene estudiantes aprobados (promedio >= 70)
vector<IEstudiante*> AcademiaController::obtenerAprobados() {
    return service->obtenerAprobados();
}

// Obtiene estudiantes ordenados por promedio descendente
vector<IEstudiante*> AcademiaController::obtenerOrdenadosPorPromedio() {
    return service->obtenerOrdenadosPorPromedio();
}

// Obtiene todos los estudiantes registrados
vector<IEstudiante*> AcademiaController::obtenerTodos() {
    return service->obtenerTodos();
}