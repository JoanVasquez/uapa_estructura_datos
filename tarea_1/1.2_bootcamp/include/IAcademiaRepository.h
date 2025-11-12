#pragma once
#include "IEstudiante.h"

using namespace std;

// Interfaz del repositorio que maneja arreglo unidimensional de estudiantes
// Implementa manipulación directa de arreglos estáticos
class IAcademiaRepository {
public:
    static const int MAX_ESTUDIANTES = 50; // Tamaño máximo del arreglo
    
    virtual ~IAcademiaRepository() = default;
    
    // Operaciones CRUD con arreglos estáticos
    virtual bool agregar(IEstudiante* estudiante) = 0;
    virtual IEstudiante* buscar(const string& matricula) = 0;
    virtual int obtenerTodos(IEstudiante* resultado[]) = 0;
    
    // Operaciones de filtrado con arreglos
    virtual int filtrarAprobados(IEstudiante* resultado[]) = 0;
    virtual void ordenarPorPromedio() = 0; // Ordenamiento burbuja
    
    // Consultas básicas
    virtual int obtenerTotal() const = 0;
    virtual IEstudiante** obtenerArreglo() = 0;
};