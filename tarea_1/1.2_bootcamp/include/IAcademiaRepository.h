#pragma once
#include "IEstudiante.h"
#include <vector>
#include <memory>
#include <functional>

using namespace std;

// Interfaz del repositorio que define operaciones CRUD para estudiantes
// Implementa el patrón Repository para abstraer el acceso a datos
class IAcademiaRepository {
public:
    virtual ~IAcademiaRepository() = default; // Destructor virtual
    
    // Operaciones CRUD básicas
    virtual void agregar(unique_ptr<IEstudiante> estudiante) = 0;  // Crear estudiante
    virtual IEstudiante* buscar(const string& matricula) = 0;      // Buscar por matrícula
    virtual vector<IEstudiante*> obtenerTodos() = 0;               // Obtener todos
    
    // Operaciones avanzadas con funciones lambda
    virtual vector<IEstudiante*> filtrar(function<bool(const IEstudiante*)> pred) = 0;        // Filtrar con predicado
    virtual void ordenar(function<bool(const IEstudiante*, const IEstudiante*)> comp) = 0;    // Ordenar con comparador
    
    // Operaciones de consulta
    virtual size_t obtenerCantidad() const = 0; // Obtener cantidad total
};