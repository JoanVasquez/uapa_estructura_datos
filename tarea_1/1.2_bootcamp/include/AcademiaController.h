#pragma once
#include "AcademiaService.h"

using namespace std;

// Controller que maneja arreglos estáticos de estudiantes
class AcademiaController {
private:
    AcademiaService* service;

public:
    explicit AcademiaController(AcademiaService* srv);
    
    // Operaciones de registro con arreglos
    bool registrarEstudiante(const string& nombre, const string& matricula);
    bool registrarCalificaciones(const string& matricula, const double notas[5]);
    
    // Operaciones que llenan arreglos resultado
    int obtenerAprobados(IEstudiante* resultado[]);
    int obtenerOrdenadosPorPromedio(IEstudiante* resultado[]);
    int obtenerTodos(IEstudiante* resultado[]);
};