#pragma once
#include "IAcademiaRepository.h"
#include <memory>

class AcademiaService {
private:
    std::unique_ptr<IAcademiaRepository> repository;

public:
    explicit AcademiaService(std::unique_ptr<IAcademiaRepository> repo);
    
    void registrarEstudiante(const std::string& nombre, const std::string& matricula);
    void registrarCalificaciones(const std::string& matricula, const std::array<double, 5>& notas);
    std::vector<IEstudiante*> obtenerAprobados();
    std::vector<IEstudiante*> obtenerOrdenadosPorPromedio();
    std::vector<IEstudiante*> obtenerTodos();
};