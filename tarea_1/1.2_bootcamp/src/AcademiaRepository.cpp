#include "../include/AcademiaRepository.h"
#include "../include/Estudiante.h"

using namespace std;

// Constructor: inicializa arreglo estático de estudiantes
AcademiaRepository::AcademiaRepository() : totalEstudiantes(0) {
    // Inicializar arreglo con punteros nulos
    for (int i = 0; i < MAX_ESTUDIANTES; i++) {
        estudiantes[i] = nullptr;
    }
}

// Destructor: libera memoria de estudiantes
AcademiaRepository::~AcademiaRepository() {
    for (int i = 0; i < totalEstudiantes; i++) {
        delete estudiantes[i];
    }
}

// Busca índice de estudiante por matrícula usando búsqueda lineal
int AcademiaRepository::buscarIndice(const string& matricula) {
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i] && estudiantes[i]->getMatricula() == matricula) {
            return i;
        }
    }
    return -1; // No encontrado
}

// Intercambia dos elementos del arreglo para algoritmos de ordenamiento
void AcademiaRepository::intercambiar(int i, int j) {
    IEstudiante* temp = estudiantes[i];
    estudiantes[i] = estudiantes[j];
    estudiantes[j] = temp;
}

// Agrega estudiante al arreglo estático con validación
bool AcademiaRepository::agregar(IEstudiante* estudiante) {
    if (!estudiante || totalEstudiantes >= MAX_ESTUDIANTES) {
        return false;
    }
    
    // Verificar duplicados usando búsqueda lineal
    if (buscarIndice(estudiante->getMatricula()) != -1) {
        return false;
    }
    
    // Agregar al final del arreglo
    estudiantes[totalEstudiantes] = estudiante;
    totalEstudiantes++;
    return true;
}

// Busca estudiante por matrícula en arreglo estático
IEstudiante* AcademiaRepository::buscar(const string& matricula) {
    int indice = buscarIndice(matricula);
    return (indice != -1) ? estudiantes[indice] : nullptr;
}

// Copia todos los estudiantes a arreglo resultado
int AcademiaRepository::obtenerTodos(IEstudiante* resultado[]) {
    for (int i = 0; i < totalEstudiantes; i++) {
        resultado[i] = estudiantes[i];
    }
    return totalEstudiantes;
}

// Filtra estudiantes aprobados usando estructura repetitiva
int AcademiaRepository::filtrarAprobados(IEstudiante* resultado[]) {
    int count = 0;
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i] && estudiantes[i]->estaAprobado()) {
            resultado[count] = estudiantes[i];
            count++;
        }
    }
    return count;
}

// Ordena estudiantes por promedio usando algoritmo burbuja
void AcademiaRepository::ordenarPorPromedio() {
    // Algoritmo de ordenamiento burbuja (descendente por promedio)
    for (int i = 0; i < totalEstudiantes - 1; i++) {
        for (int j = 0; j < totalEstudiantes - i - 1; j++) {
            // Condicional anidada para comparar promedios
            if (estudiantes[j]->getPromedio() < estudiantes[j + 1]->getPromedio()) {
                intercambiar(j, j + 1);
            }
        }
    }
}