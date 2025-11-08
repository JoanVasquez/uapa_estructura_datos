#include "../include/AcademiaService.h"
#include "../include/Estudiante.h"
#include <stdexcept>

using namespace std;

// Constructor que recibe el repositorio por inyección de dependencias
AcademiaService::AcademiaService(unique_ptr<IAcademiaRepository> repo)
    : repository(move(repo)) {}

// Registra un nuevo estudiante en el sistema
void AcademiaService::registrarEstudiante(const string& nombre, const string& matricula) {
    // Crear un nuevo estudiante usando Factory pattern
    auto estudiante = make_unique<Estudiante>(nombre, matricula);
    repository->agregar(move(estudiante));
}

// Registra las calificaciones de un estudiante existente
void AcademiaService::registrarCalificaciones(const string& matricula, 
                                             const array<double, 5>& notas) {
    // Buscar el estudiante por matrícula
    auto* estudiante = repository->buscar(matricula);
    if (!estudiante) {
        throw runtime_error("Estudiante no encontrado: " + matricula);
    }
    
    // Registrar las calificaciones (esto recalcula promedio y estado)
    estudiante->registrarCalificaciones(notas);
}

// Obtiene todos los estudiantes aprobados (promedio >= 70)
vector<IEstudiante*> AcademiaService::obtenerAprobados() {
    return repository->filtrar([](const IEstudiante* est) {
        return est->estaAprobado(); // Usar lógica de negocio del estudiante
    });
}

// Obtiene estudiantes ordenados por promedio de mayor a menor
vector<IEstudiante*> AcademiaService::obtenerOrdenadosPorPromedio() {
    // Ordenar el repositorio usando comparador lambda
    repository->ordenar([](const IEstudiante* a, const IEstudiante* b) {
        return a->getPromedio() > b->getPromedio(); // Orden descendente
    });
    return repository->obtenerTodos();
}

// Obtiene todos los estudiantes sin filtros
vector<IEstudiante*> AcademiaService::obtenerTodos() {
    return repository->obtenerTodos();
}