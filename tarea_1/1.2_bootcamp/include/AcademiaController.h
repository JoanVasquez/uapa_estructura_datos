#pragma once
#include "AcademiaService.h"
#include <memory>

using namespace std;

/**
 * Controller para el sistema académico de calificaciones.
 * Coordina operaciones entre UI y Service siguiendo patrón MVC.
 * Maneja registro de estudiantes, calificaciones y consultas.
 */
class AcademiaController {
private:
    unique_ptr<AcademiaService> service; // Servicio de lógica de negocio

public:
    explicit AcademiaController(unique_ptr<AcademiaService> srv);
    
    // Operaciones de registro
    void registrarEstudiante(const string& nombre, const string& matricula);
    void registrarCalificaciones(const string& matricula, const array<double, 5>& notas);
    
    // Operaciones de consulta y filtrado
    vector<IEstudiante*> obtenerAprobados();
    vector<IEstudiante*> obtenerOrdenadosPorPromedio();
    vector<IEstudiante*> obtenerTodos();
};