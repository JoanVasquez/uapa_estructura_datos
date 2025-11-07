#include "../include/AlmacenService.h"
#include "../include/AlmacenRepository.h"
#include <iostream>
#include <iomanip>

class AlmacenUI {
private:
    AlmacenService service;

public:
    AlmacenUI() : service(std::make_unique<AlmacenRepository>()) {}

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
        std::cout << "\n=== ALMACÉN DE COMPONENTES ===\n"
                  << "1. Registrar componente nacional\n"
                  << "2. Registrar componente importado\n"
                  << "3. Modificar cantidad\n"
                  << "4. Modificar nivel mínimo\n"
                  << "5. Nacionales por precio\n"
                  << "6. Importados por país\n"
                  << "7. Componentes bajo stock\n"
                  << "0. Salir\nOpción: ";
    }

    void procesarOpcion(int opcion) {
        switch (opcion) {
            case 1: registrarNacional(); break;
            case 2: registrarImportado(); break;
            case 3: modificarCantidad(); break;
            case 4: modificarNivelMinimo(); break;
            case 5: listarNacionalesPorPrecio(); break;
            case 6: listarImportadosPorPais(); break;
            case 7: listarBajoStock(); break;
            case 0: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opción inválida\n";
        }
    }

    void registrarNacional() {
        std::string codigo, nombre, empresa;
        double precio;
        int cantidad, minimo;
        
        std::cout << "Código: "; std::cin >> codigo;
        std::cout << "Nombre: "; std::cin >> nombre;
        std::cout << "Precio costo: "; std::cin >> precio;
        std::cout << "Cantidad: "; std::cin >> cantidad;
        std::cout << "Empresa: "; std::cin >> empresa;
        std::cout << "Nivel mínimo: "; std::cin >> minimo;
        
        service.registrarNacional(codigo, nombre, precio, cantidad, empresa, minimo);
        std::cout << "Componente registrado exitosamente\n";
    }

    void registrarImportado() {
        std::string codigo, nombre, pais;
        double precio, precioUSD;
        int cantidad, minimo;
        
        std::cout << "Código: "; std::cin >> codigo;
        std::cout << "Nombre: "; std::cin >> nombre;
        std::cout << "Precio costo: "; std::cin >> precio;
        std::cout << "Cantidad: "; std::cin >> cantidad;
        std::cout << "País: "; std::cin >> pais;
        std::cout << "Precio USD: "; std::cin >> precioUSD;
        std::cout << "Nivel mínimo: "; std::cin >> minimo;
        
        service.registrarImportado(codigo, nombre, precio, cantidad, pais, precioUSD, minimo);
        std::cout << "Componente registrado exitosamente\n";
    }

    void modificarCantidad() {
        std::string codigo;
        int cantidad;
        std::cout << "Código: "; std::cin >> codigo;
        std::cout << "Nueva cantidad: "; std::cin >> cantidad;
        service.modificarCantidad(codigo, cantidad);
        std::cout << "Cantidad actualizada\n";
    }

    void modificarNivelMinimo() {
        std::string codigo;
        int nivel;
        std::cout << "Código: "; std::cin >> codigo;
        std::cout << "Nuevo nivel mínimo: "; std::cin >> nivel;
        service.modificarNivelMinimo(codigo, nivel);
        std::cout << "Nivel mínimo actualizado\n";
    }

    void listarNacionalesPorPrecio() {
        double minimo;
        std::cout << "Precio mínimo: "; std::cin >> minimo;
        auto componentes = service.nacionalesPorPrecio(minimo);
        mostrarComponentes(componentes);
    }

    void listarImportadosPorPais() {
        std::string pais;
        std::cout << "País: "; std::cin >> pais;
        auto componentes = service.importadosPorPais(pais);
        mostrarComponentes(componentes);
    }

    void listarBajoStock() {
        auto componentes = service.componentesBajoStock();
        std::cout << "\n=== COMPONENTES BAJO STOCK ===\n";
        mostrarComponentes(componentes);
    }

    void mostrarComponentes(const std::vector<IComponente*>& componentes) {
        if (componentes.empty()) {
            std::cout << "No se encontraron componentes\n";
            return;
        }
        
        std::cout << std::fixed << std::setprecision(2);
        for (const auto* c : componentes) {
            std::cout << c->getCodigo() << " | " << c->getNombre() 
                      << " | $" << c->calcularPrecioVenta() 
                      << " | Stock: " << c->getCantidad() 
                      << " | " << c->getTipo() << std::endl;
        }
    }
};

int main() {
    AlmacenUI app;
    app.ejecutar();
    return 0;
}