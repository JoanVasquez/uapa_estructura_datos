#include "../include/AcademiaRepository.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

// Agrega un nuevo estudiante al repositorio con validación de duplicados
void AcademiaRepository::agregar(unique_ptr<IEstudiante> estudiante) {
    if (!estudiante) {
        throw invalid_argument("Estudiante no puede ser nulo");
    }
    
    // Verificar que no exista un estudiante con la misma matrícula
    if (buscar(estudiante->getMatricula())) {
        throw runtime_error("Matrícula duplicada: " + estudiante->getMatricula());
    }
    
    // Agregar el estudiante al contenedor
    estudiantes.push_back(move(estudiante));
}

// Busca un estudiante por su número de matrícula usando algoritmo STL
IEstudiante* AcademiaRepository::buscar(const string& matricula) {
    auto it = find_if(estudiantes.begin(), estudiantes.end(),
        [&matricula](const auto& est) { return est->getMatricula() == matricula; });
    
    return (it != estudiantes.end()) ? it->get() : nullptr;
}

// Obtiene todos los estudiantes como punteros raw para consulta
vector<IEstudiante*> AcademiaRepository::obtenerTodos() {
    vector<IEstudiante*> resultado;
    resultado.reserve(estudiantes.size()); // Reservar memoria para eficiencia
    
    // Convertir unique_ptr a raw pointer para consulta
    for (const auto& est : estudiantes) {
        resultado.push_back(est.get());
    }
    
    return resultado;
}

// Filtra estudiantes usando un predicado (función lambda)
vector<IEstudiante*> AcademiaRepository::filtrar(function<bool(const IEstudiante*)> pred) {
    vector<IEstudiante*> resultado;
    
    // Aplicar el predicado a cada estudiante
    for (const auto& est : estudiantes) {
        if (pred(est.get())) {
            resultado.push_back(est.get());
        }
    }
    
    return resultado;
}

// Ordena los estudiantes usando un comparador personalizado
void AcademiaRepository::ordenar(function<bool(const IEstudiante*, const IEstudiante*)> comp) {
    sort(estudiantes.begin(), estudiantes.end(),
        [&comp](const auto& a, const auto& b) { return comp(a.get(), b.get()); });
}