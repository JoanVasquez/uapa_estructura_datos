#pragma once
#include "IEstudiante.h"

class Estudiante : public IEstudiante {
private:
    std::string nombre, matricula;
    std::array<double, 5> calificaciones;
    double promedio;
    std::string estado;
    static constexpr double NOTA_APROBACION = 70.0;
    
    void calcularPromedio();
    void determinarEstado();
    void validarDatos() const;

public:
    Estudiante(const std::string& nombre, const std::string& matricula);
    
    std::string getNombre() const override { return nombre; }
    std::string getMatricula() const override { return matricula; }
    double getPromedio() const override { return promedio; }
    std::string getEstado() const override { return estado; }
    void registrarCalificaciones(const std::array<double, 5>& notas) override;
    bool estaAprobado() const override { return promedio >= NOTA_APROBACION; }
};