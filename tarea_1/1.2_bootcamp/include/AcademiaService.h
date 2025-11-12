#pragma once
#include "IAcademiaRepository.h"

using namespace std;

// Servicio de negocio que maneja arreglos estáticos de estudiantes
class AcademiaService {
private:
    IAcademiaRepository* repository; // Repositorio inyectado

public:
    explicit AcademiaService(IAcademiaRepository* repo);
    
    // Operaciones de registro
    bool registrarEstudiante(const string& nombre, const string& matricula);
    bool registrarCalificaciones(const string& matricula, const double notas[5]);
    
    // Consultas que llenan arreglos estáticos
    int obtenerAprobados(IEstudiante* resultado[]);
    int obtenerOrdenadosPorPromedio(IEstudiante* resultado[]);
    int obtenerTodos(IEstudiante* resultado[]);
};