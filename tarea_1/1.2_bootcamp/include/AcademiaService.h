#pragma once
#include "IAcademiaRepository.h"
#include <memory>

using namespace std;

// Servicio de negocio que encapsula la lógica del sistema académico
// Implementa el patrón Service Layer para separar lógica de negocio
class AcademiaService {
private:
    unique_ptr<IAcademiaRepository> repository; // Repositorio inyectado por dependencia

public:
    // Constructor que recibe el repositorio por inyección de dependencias
    explicit AcademiaService(unique_ptr<IAcademiaRepository> repo);
    
    // Operaciones de registro y actualización
    void registrarEstudiante(const string& nombre, const string& matricula);           // Crear nuevo estudiante
    void registrarCalificaciones(const string& matricula, const array<double, 5>& notas); // Asignar calificaciones
    
    // Consultas de negocio con filtros específicos
    vector<IEstudiante*> obtenerAprobados();              // Estudiantes con promedio >= 70
    vector<IEstudiante*> obtenerOrdenadosPorPromedio();   // Ordenados por promedio descendente
    vector<IEstudiante*> obtenerTodos();                  // Todos los estudiantes
};