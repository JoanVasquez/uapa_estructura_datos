#include "../include/AcademiaService.h"
#include "../include/Estudiante.h"

using namespace std;

// Constructor que recibe el repositorio
AcademiaService::AcademiaService(IAcademiaRepository* repo) : repository(repo) {}

// Registra un nuevo estudiante usando arreglo estático
bool AcademiaService::registrarEstudiante(const string& nombre, const string& matricula) {
    Estudiante* estudiante = new Estudiante(nombre, matricula);
    return repository->agregar(estudiante);
}

// Registra calificaciones usando arreglo simple
bool AcademiaService::registrarCalificaciones(const string& matricula, const double notas[5]) {
    IEstudiante* estudiante = repository->buscar(matricula);
    if (!estudiante) return false;
    
    estudiante->registrarCalificaciones(notas);
    return true;
}

// Obtiene aprobados llenando arreglo resultado
int AcademiaService::obtenerAprobados(IEstudiante* resultado[]) {
    return repository->filtrarAprobados(resultado);
}

// Obtiene estudiantes ordenados por promedio
int AcademiaService::obtenerOrdenadosPorPromedio(IEstudiante* resultado[]) {
    repository->ordenarPorPromedio();
    return repository->obtenerTodos(resultado);
}

// Obtiene todos los estudiantes
int AcademiaService::obtenerTodos(IEstudiante* resultado[]) {
    return repository->obtenerTodos(resultado);
}