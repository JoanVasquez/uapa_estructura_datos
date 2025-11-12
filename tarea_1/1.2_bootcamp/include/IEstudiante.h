#pragma once
#include <string>
#include <array>

using namespace std;

// Interfaz que define el contrato para todos los estudiantes
// Implementa el principio de Inversión de Dependencias (SOLID)
class IEstudiante {
public:
    virtual ~IEstudiante() = default; // Destructor virtual para polimorfismo
    
    // Métodos getter puros para obtener información del estudiante
    virtual string getNombre() const = 0;     // Nombre completo del estudiante
    virtual string getMatricula() const = 0;  // Número de matrícula único
    virtual double getPromedio() const = 0;   // Promedio calculado de las 5 notas
    virtual string getEstado() const = 0;     // Estado académico (Aprobado/Reprobado)
    
    // Métodos de operación puros
    virtual void registrarCalificaciones(const double notas[5]) = 0; // Registrar las 5 calificaciones
    virtual bool estaAprobado() const = 0;    // Verificar si el promedio es >= 70
};