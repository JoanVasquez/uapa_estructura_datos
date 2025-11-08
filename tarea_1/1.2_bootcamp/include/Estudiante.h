#pragma once
#include "IEstudiante.h"

using namespace std;

// Clase concreta que implementa un estudiante del bootcamp
// Maneja 5 calificaciones y calcula promedio automáticamente
class Estudiante : public IEstudiante {
private:
    string nombre, matricula;        // Datos identificativos del estudiante
    array<double, 5> calificaciones; // Arreglo de 5 calificaciones
    double promedio;                 // Promedio calculado automáticamente
    string estado;                   // Estado académico actual
    static constexpr double NOTA_APROBACION = 70.0; // Nota mínima para aprobar
    
    // Métodos privados para cálculos internos
    void calcularPromedio();   // Calcula el promedio de las 5 notas
    void determinarEstado();   // Determina si está aprobado o reprobado
    void validarDatos() const; // Valida que los datos sean correctos

public:
    // Constructor que inicializa un estudiante con nombre y matrícula
    Estudiante(const string& nombre, const string& matricula);
    
    // Implementación de métodos de la interfaz
    string getNombre() const override { return nombre; }
    string getMatricula() const override { return matricula; }
    double getPromedio() const override { return promedio; }
    string getEstado() const override { return estado; }
    void registrarCalificaciones(const array<double, 5>& notas) override;
    bool estaAprobado() const override { return promedio >= NOTA_APROBACION; }
};