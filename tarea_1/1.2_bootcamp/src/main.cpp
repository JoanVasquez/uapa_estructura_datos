#include "../include/AcademiaController.h"
#include "../include/AcademiaService.h"
#include "../include/AcademiaRepository.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Clase que maneja la interfaz de usuario para el sistema académico
// Implementa el patrón MVC como controlador
class AcademiaUI {
private:
    AcademiaController* controller;
    AcademiaService* service;
    AcademiaRepository* repository;

public:
    AcademiaUI() {
        repository = new AcademiaRepository();
        service = new AcademiaService(repository);
        controller = new AcademiaController(service);
    }
    
    ~AcademiaUI() {
        delete controller;
        delete service;
        delete repository;
    }

    // Método principal que ejecuta el bucle de la interfaz de usuario
    void ejecutar() {
        int opcion;
        do {
            mostrarMenu();
            cin >> opcion;
            try {
                procesarOpcion(opcion); // Procesar la opción seleccionada
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl; // Manejo de errores
            }
        } while (opcion != 0); // Continuar hasta que el usuario elija salir
    }

private:
    // Muestra el menú principal con todas las opciones disponibles
    void mostrarMenu() {
        cout << "\n=== SISTEMA ACADEMICO ===\n"
                  << "1. Registrar estudiante\n"
                  << "2. Registrar calificaciones\n"
                  << "3. Mostrar aprobados\n"
                  << "4. Ordenar por promedio\n"
                  << "5. Mostrar todos\n"
                  << "0. Salir\nOpcion: ";
    }

    // Procesa la opción seleccionada por el usuario usando patrón Command
    void procesarOpcion(int opcion) {
        switch (opcion) {
            case 1: registrarEstudiante(); break;     // Crear nuevo estudiante
            case 2: registrarCalificaciones(); break; // Asignar calificaciones
            case 3: mostrarAprobados(); break;        // Filtrar aprobados
            case 4: mostrarOrdenados(); break;        // Ordenar por promedio
            case 5: mostrarTodos(); break;            // Mostrar todos
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    }

    // Registra un nuevo estudiante en el sistema
    void registrarEstudiante() {
        string nombre, matricula;
        cin.ignore(); // Limpiar buffer de entrada
        cout << "Nombre: ";
        getline(cin, nombre); // Leer nombre completo con espacios
        cout << "Matricula: ";
        getline(cin, matricula);
        
        if (controller->registrarEstudiante(nombre, matricula)) {
            cout << "Estudiante registrado exitosamente\n";
        } else {
            cout << "Error: No se pudo registrar el estudiante\n";
        }
    }

    // Registra las 5 calificaciones usando arreglo simple
    void registrarCalificaciones() {
        string matricula;
        double notas[5];
        
        cin.ignore();
        cout << "Matricula: ";
        getline(cin, matricula);
        
        cout << "Ingrese 5 calificaciones:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Calificacion " << (i + 1) << ": ";
            cin >> notas[i];
        }
        
        if (controller->registrarCalificaciones(matricula, notas)) {
            cout << "Calificaciones registradas exitosamente\n";
        } else {
            cout << "Error: Estudiante no encontrado\n";
        }
    }

    // Muestra aprobados usando arreglo estático
    void mostrarAprobados() {
        IEstudiante* aprobados[IAcademiaRepository::MAX_ESTUDIANTES];
        int total = controller->obtenerAprobados(aprobados);
        cout << "\n=== ESTUDIANTES APROBADOS ===\n";
        mostrarEstudiantes(aprobados, total);
    }

    // Muestra ordenados usando arreglo estático
    void mostrarOrdenados() {
        IEstudiante* ordenados[IAcademiaRepository::MAX_ESTUDIANTES];
        int total = controller->obtenerOrdenadosPorPromedio(ordenados);
        cout << "\n=== ESTUDIANTES ORDENADOS POR PROMEDIO ===\n";
        mostrarEstudiantes(ordenados, total);
    }

    // Muestra todos usando arreglo estático
    void mostrarTodos() {
        IEstudiante* todos[IAcademiaRepository::MAX_ESTUDIANTES];
        int total = controller->obtenerTodos(todos);
        cout << "\n=== TODOS LOS ESTUDIANTES ===\n";
        mostrarEstudiantes(todos, total);
    }

    // Muestra arreglo de estudiantes con bucle tradicional
    void mostrarEstudiantes(IEstudiante* estudiantes[], int total) {
        if (total == 0) {
            cout << "No hay estudiantes para mostrar\n";
            return;
        }
        
        cout << fixed << setprecision(2);
        for (int i = 0; i < total; i++) {
            IEstudiante* est = estudiantes[i];
            cout << est->getMatricula() << " | " 
                      << est->getNombre() << " | "
                      << "Promedio: " << est->getPromedio() << " | "
                      << est->getEstado() << endl;
        }
    }
};

// Función principal que inicia la aplicación del sistema académico
int main() {
    // Crear la interfaz de usuario y ejecutar el sistema
    AcademiaUI app;
    app.ejecutar();
    return 0;
}