#pragma once
#include "IAcademiaRepository.h"

using namespace std;

// Implementación concreta del repositorio usando un vector en memoria
// Almacena estudiantes usando smart pointers para manejo automático de memoria
class AcademiaRepository : public IAcademiaRepository {
private:
    vector<unique_ptr<IEstudiante>> estudiantes; // Contenedor de estudiantes con RAII

public:
    // Implementación de operaciones CRUD
    void agregar(unique_ptr<IEstudiante> estudiante) override;     // Agregar nuevo estudiante
    IEstudiante* buscar(const string& matricula) override;         // Buscar por matrícula
    vector<IEstudiante*> obtenerTodos() override;                  // Obtener todos los estudiantes
    
    // Operaciones avanzadas con algoritmos STL
    vector<IEstudiante*> filtrar(function<bool(const IEstudiante*)> pred) override;        // Filtrar con predicado
    void ordenar(function<bool(const IEstudiante*, const IEstudiante*)> comp) override;    // Ordenar con comparador
    
    // Consulta de tamaño inline
    size_t obtenerCantidad() const override { return estudiantes.size(); }
};