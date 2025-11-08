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
    AcademiaController controller; // Controlador para operaciones académicas

public:
    // Constructor que inicializa el controlador con servicio y repositorio
    AcademiaUI() : controller(make_unique<AcademiaService>(make_unique<AcademiaRepository>())) {}

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
        cout << "\n=== SISTEMA ACADÉMICO ===\n"
                  << "1. Registrar estudiante\n"
                  << "2. Registrar calificaciones\n"
                  << "3. Mostrar aprobados\n"
                  << "4. Ordenar por promedio\n"
                  << "5. Mostrar todos\n"
                  << "0. Salir\nOpción: ";
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
            default: cout << "Opción inválida\n";
        }
    }

    // Registra un nuevo estudiante en el sistema
    void registrarEstudiante() {
        string nombre, matricula;
        cout << "Nombre: ";
        cin.ignore(); // Limpiar buffer de entrada
        getline(cin, nombre); // Leer nombre completo con espacios
        cout << "Matrícula: ";
        cin >> matricula;
        
        controller.registrarEstudiante(nombre, matricula);
        cout << "Estudiante registrado exitosamente\n";
    }

    // Registra las 5 calificaciones de un estudiante
    void registrarCalificaciones() {
        string matricula;
        array<double, 5> notas;
        
        cout << "Matrícula: ";
        cin >> matricula;
        
        // Solicitar las 5 calificaciones
        cout << "Ingrese 5 calificaciones:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Calificación " << (i + 1) << ": ";
            cin >> notas[i];
        }
        
        controller.registrarCalificaciones(matricula, notas);
        cout << "Calificaciones registradas exitosamente\n";
    }

    // Muestra solo los estudiantes aprobados (promedio >= 70)
    void mostrarAprobados() {
        auto aprobados = controller.obtenerAprobados();
        cout << "\n=== ESTUDIANTES APROBADOS ===\n";
        mostrarEstudiantes(aprobados);
    }

    // Muestra estudiantes ordenados por promedio de mayor a menor
    void mostrarOrdenados() {
        auto ordenados = controller.obtenerOrdenadosPorPromedio();
        cout << "\n=== ESTUDIANTES ORDENADOS POR PROMEDIO ===\n";
        mostrarEstudiantes(ordenados);
    }

    // Muestra todos los estudiantes registrados
    void mostrarTodos() {
        auto todos = controller.obtenerTodos();
        cout << "\n=== TODOS LOS ESTUDIANTES ===\n";
        mostrarEstudiantes(todos);
    }

    // Método auxiliar que muestra una lista de estudiantes en formato tabular
    void mostrarEstudiantes(const vector<IEstudiante*>& estudiantes) {
        if (estudiantes.empty()) {
            cout << "No hay estudiantes para mostrar\n";
            return;
        }
        
        // Configurar formato de salida para promedios
        cout << fixed << setprecision(2);
        for (const auto* est : estudiantes) {
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