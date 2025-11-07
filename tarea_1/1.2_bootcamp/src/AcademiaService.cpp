#include "../include/AcademiaService.h"
#include "../include/Estudiante.h"
#include <stdexcept>

AcademiaService::AcademiaService(std::unique_ptr<IAcademiaRepository> repo)
    : repository(std::move(repo)) {}

void AcademiaService::registrarEstudiante(const std::string& nombre, const std::string& matricula) {
    auto estudiante = std::make_unique<Estudiante>(nombre, matricula);
    repository->agregar(std::move(estudiante));
}

void AcademiaService::registrarCalificaciones(const std::string& matricula, 
                                             const std::array<double, 5>& notas) {
    auto* estudiante = repository->buscar(matricula);
    if (!estudiante) {
        throw std::runtime_error("Estudiante no encontrado: " + matricula);
    }
    
    estudiante->registrarCalificaciones(notas);
}

std::vector<IEstudiante*> AcademiaService::obtenerAprobados() {
    return repository->filtrar([](const IEstudiante* est) {
        return est->estaAprobado();
    });
}

std::vector<IEstudiante*> AcademiaService::obtenerOrdenadosPorPromedio() {
    repository->ordenar([](const IEstudiante* a, const IEstudiante* b) {
        return a->getPromedio() > b->getPromedio(); // Descendente
    });
    return repository->obtenerTodos();
}

std::vector<IEstudiante*> AcademiaService::obtenerTodos() {
    return repository->obtenerTodos();
}