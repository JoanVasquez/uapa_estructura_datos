#pragma once
#include "IAcademiaRepository.h"

class AcademiaRepository : public IAcademiaRepository {
private:
    std::vector<std::unique_ptr<IEstudiante>> estudiantes;

public:
    void agregar(std::unique_ptr<IEstudiante> estudiante) override;
    IEstudiante* buscar(const std::string& matricula) override;
    std::vector<IEstudiante*> obtenerTodos() override;
    std::vector<IEstudiante*> filtrar(std::function<bool(const IEstudiante*)> pred) override;
    void ordenar(std::function<bool(const IEstudiante*, const IEstudiante*)> comp) override;
    size_t obtenerCantidad() const override { return estudiantes.size(); }
};