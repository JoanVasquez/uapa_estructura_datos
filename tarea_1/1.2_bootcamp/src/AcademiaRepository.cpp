#include "../include/AcademiaRepository.h"
#include <stdexcept>
#include <algorithm>

void AcademiaRepository::agregar(std::unique_ptr<IEstudiante> estudiante) {
    if (!estudiante) {
        throw std::invalid_argument("Estudiante no puede ser nulo");
    }
    
    if (buscar(estudiante->getMatricula())) {
        throw std::runtime_error("Matrícula duplicada: " + estudiante->getMatricula());
    }
    
    estudiantes.push_back(std::move(estudiante));
}

IEstudiante* AcademiaRepository::buscar(const std::string& matricula) {
    auto it = std::find_if(estudiantes.begin(), estudiantes.end(),
        [&matricula](const auto& est) { return est->getMatricula() == matricula; });
    
    return (it != estudiantes.end()) ? it->get() : nullptr;
}

std::vector<IEstudiante*> AcademiaRepository::obtenerTodos() {
    std::vector<IEstudiante*> resultado;
    resultado.reserve(estudiantes.size());
    
    for (const auto& est : estudiantes) {
        resultado.push_back(est.get());
    }
    
    return resultado;
}

std::vector<IEstudiante*> AcademiaRepository::filtrar(std::function<bool(const IEstudiante*)> pred) {
    std::vector<IEstudiante*> resultado;
    
    for (const auto& est : estudiantes) {
        if (pred(est.get())) {
            resultado.push_back(est.get());
        }
    }
    
    return resultado;
}

void AcademiaRepository::ordenar(std::function<bool(const IEstudiante*, const IEstudiante*)> comp) {
    std::sort(estudiantes.begin(), estudiantes.end(),
        [&comp](const auto& a, const auto& b) { return comp(a.get(), b.get()); });
}