#pragma once
#include "IAcademiaRepository.h"

using namespace std;

// Implementación del repositorio usando arreglo unidimensional estático
// Maneja estudiantes con manipulación directa de arreglos
class AcademiaRepository : public IAcademiaRepository {
private:
    IEstudiante* estudiantes[MAX_ESTUDIANTES]; // Arreglo estático de estudiantes
    int totalEstudiantes; // Contador de estudiantes actuales
    
    // Funciones auxiliares para manipulación de arreglos
    int buscarIndice(const string& matricula);
    void intercambiar(int i, int j); // Para algoritmos de ordenamiento

public:
    AcademiaRepository();
    ~AcademiaRepository();
    
    // Implementación con arreglos estáticos
    bool agregar(IEstudiante* estudiante) override;
    IEstudiante* buscar(const string& matricula) override;
    int obtenerTodos(IEstudiante* resultado[]) override;
    
    // Operaciones de filtrado y ordenamiento con arreglos
    int filtrarAprobados(IEstudiante* resultado[]) override;
    void ordenarPorPromedio() override; // Algoritmo burbuja
    
    // Consultas básicas
    int obtenerTotal() const override { return totalEstudiantes; }
    IEstudiante** obtenerArreglo() override { return estudiantes; }
};