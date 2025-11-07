#include "../include/AcademiaService.h"
#include "../include/AcademiaRepository.h"
#include <iostream>
#include <iomanip>

class AcademiaUI {
private:
    AcademiaService service;

public:
    AcademiaUI() : service(std::make_unique<AcademiaRepository>()) {}

    void ejecutar() {
        int opcion;
        do {
            mostrarMenu();
            std::cin >> opcion;
            try {
                procesarOpcion(opcion);
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        } while (opcion != 0);
    }

private:
    void mostrarMenu() {
        std::cout << "\n=== SISTEMA ACADÉMICO ===\n"
                  << "1. Registrar estudiante\n"
                  << "2. Registrar calificaciones\n"
                  << "3. Mostrar aprobados\n"
                  << "4. Ordenar por promedio\n"
                  << "5. Mostrar todos\n"
                  << "0. Salir\nOpción: ";
    }

    void procesarOpcion(int opcion) {
        switch (opcion) {
            case 1: registrarEstudiante(); break;
            case 2: registrarCalificaciones(); break;
            case 3: mostrarAprobados(); break;
            case 4: mostrarOrdenados(); break;
            case 5: mostrarTodos(); break;
            case 0: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opción inválida\n";
        }
    }

    void registrarEstudiante() {
        std::string nombre, matricula;
        std::cout << "Nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cout << "Matrícula: ";
        std::cin >> matricula;
        
        service.registrarEstudiante(nombre, matricula);
        std::cout << "Estudiante registrado exitosamente\n";
    }

    void registrarCalificaciones() {
        std::string matricula;
        std::array<double, 5> notas;
        
        std::cout << "Matrícula: ";
        std::cin >> matricula;
        
        std::cout << "Ingrese 5 calificaciones:\n";
        for (int i = 0; i < 5; ++i) {
            std::cout << "Calificación " << (i + 1) << ": ";
            std::cin >> notas[i];
        }
        
        service.registrarCalificaciones(matricula, notas);
        std::cout << "Calificaciones registradas exitosamente\n";
    }

    void mostrarAprobados() {
        auto aprobados = service.obtenerAprobados();
        std::cout << "\n=== ESTUDIANTES APROBADOS ===\n";
        mostrarEstudiantes(aprobados);
    }

    void mostrarOrdenados() {
        auto ordenados = service.obtenerOrdenadosPorPromedio();
        std::cout << "\n=== ESTUDIANTES ORDENADOS POR PROMEDIO ===\n";
        mostrarEstudiantes(ordenados);
    }

    void mostrarTodos() {
        auto todos = service.obtenerTodos();
        std::cout << "\n=== TODOS LOS ESTUDIANTES ===\n";
        mostrarEstudiantes(todos);
    }

    void mostrarEstudiantes(const std::vector<IEstudiante*>& estudiantes) {
        if (estudiantes.empty()) {
            std::cout << "No hay estudiantes para mostrar\n";
            return;
        }
        
        std::cout << std::fixed << std::setprecision(2);
        for (const auto* est : estudiantes) {
            std::cout << est->getMatricula() << " | " 
                      << est->getNombre() << " | "
                      << "Promedio: " << est->getPromedio() << " | "
                      << est->getEstado() << std::endl;
        }
    }
};

int main() {
    AcademiaUI app;
    app.ejecutar();
    return 0;
}