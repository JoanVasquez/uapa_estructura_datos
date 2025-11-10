#include "../include/AlmacenController.h"
#include "../include/AlmacenService.h"
#include "../include/AlmacenRepository.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Clase que maneja la interfaz de usuario para el sistema de almacén
// Implementa el patrón MVC como controlador
class AlmacenUI {
private:
  AlmacenController controller; // Controlador para operaciones del almacén

public:
  // Constructor que inicializa el controlador con servicio y repositorio
  AlmacenUI() : controller(make_unique<AlmacenService>(make_unique<AlmacenRepository>())) {}

  // Método principal que ejecuta el bucle de la interfaz de usuario
  void ejecutar() {
    int opcion;
    do {
      mostrarMenu();
      cin >> opcion;
      try {
        procesarOpcion(opcion); // Procesar la opción seleccionada
      } catch (const exception &e) {
        cout << "Error: " << e.what() << endl; // Manejo de errores
      }
    } while (opcion != 0); // Continuar hasta que el usuario elija salir
  }

private:
  // Muestra el menú principal con todas las opciones disponibles
  void mostrarMenu() {
    cout << "\n=== ALMACÉN DE COMPONENTES ===\n"
         << "1. Registrar componente nacional\n"
         << "2. Registrar componente importado\n"
         << "3. Modificar cantidad\n"
         << "4. Modificar nivel mínimo\n"
         << "5. Nacionales por precio\n"
         << "6. Importados por país\n"
         << "7. Componentes bajo stock\n"
         << "0. Salir\nOpción: ";
  }

  // Procesa la opción seleccionada por el usuario usando patrón Command
  void procesarOpcion(int opcion) {
    switch (opcion) {
    case 1:
      registrarNacional(); // Registrar componente de fabricación nacional
      break;
    case 2:
      registrarImportado(); // Registrar componente importado
      break;
    case 3:
      modificarCantidad(); // Actualizar stock de un componente
      break;
    case 4:
      modificarNivelMinimo(); // Cambiar umbral mínimo de inventario
      break;
    case 5:
      listarNacionalesPorPrecio(); // Filtrar nacionales por precio
      break;
    case 6:
      listarImportadosPorPais(); // Filtrar importados por país
      break;
    case 7:
      listarBajoStock(); // Mostrar componentes con stock crítico
      break;
    case 0:
      cout << "Saliendo...\n";
      break;
    default:
      cout << "Opción inválida\n";
      break;
    }
  }

  // Registra un nuevo componente de fabricación nacional
  void registrarNacional() {
    string codigo, nombre, empresa;
    double precio;
    int cantidad, minimo;

    cin.ignore(); // Limpiar buffer
    // Solicitar datos del componente nacional
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Precio costo: ";
    cin >> precio;
    cout << "Cantidad: ";
    cin >> cantidad;
    cin.ignore(); // Limpiar buffer después de números
    cout << "Empresa: ";
    getline(cin, empresa);
    cout << "Nivel mínimo: ";
    cin >> minimo;

    // Crear y almacenar el componente usando el servicio
    controller.registrarComponenteNacional(codigo, nombre, precio, cantidad, empresa, minimo);
    cout << "Componente registrado exitosamente\n";
  }

  // Registra un nuevo componente importado con precio en USD
  void registrarImportado() {
    string codigo, nombre, pais;
    double precio, precioUSD;
    int cantidad, minimo;

    cin.ignore(); // Limpiar buffer
    // Solicitar datos del componente importado
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Precio costo: ";
    cin >> precio;
    cout << "Cantidad: ";
    cin >> cantidad;
    cin.ignore(); // Limpiar buffer después de números
    cout << "País: ";
    getline(cin, pais);
    cout << "Precio USD: ";
    cin >> precioUSD;
    cout << "Nivel mínimo: ";
    cin >> minimo;

    // Crear y almacenar el componente importado usando el servicio
    controller.registrarComponenteImportado(codigo, nombre, precio, cantidad, pais, precioUSD, minimo);
    cout << "Componente registrado exitosamente\n";
  }

  // Modifica la cantidad en stock de un componente específico
  void modificarCantidad() {
    string codigo;
    int cantidad;
    cin.ignore(); // Limpiar buffer
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nueva cantidad: ";
    cin >> cantidad;
    controller.modificarCantidad(codigo, cantidad);
    cout << "Cantidad actualizada\n";
  }

  // Modifica el nivel mínimo de inventario de un componente
  void modificarNivelMinimo() {
    string codigo;
    int nivel;
    cin.ignore(); // Limpiar buffer
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nuevo nivel mínimo: ";
    cin >> nivel;
    controller.modificarNivelMinimo(codigo, nivel);
    cout << "Nivel mínimo actualizado\n";
  }

  // Lista componentes nacionales que superan un precio mínimo
  void listarNacionalesPorPrecio() {
    double minimo;
    cout << "Precio mínimo: ";
    cin >> minimo;
    auto componentes = controller.obtenerNacionalesPorPrecio(minimo);
    mostrarComponentes(componentes);
  }

  // Lista componentes importados de un país específico
  void listarImportadosPorPais() {
    string pais;
    cin.ignore(); // Limpiar buffer
    cout << "País: ";
    getline(cin, pais);
    auto componentes = controller.obtenerImportadosPorPais(pais);
    mostrarComponentes(componentes);
  }

  // Lista todos los componentes que están bajo el nivel mínimo de stock
  void listarBajoStock() {
    auto componentes = controller.obtenerComponentesBajoStock();
    cout << "\n=== COMPONENTES BAJO STOCK ===\n";
    mostrarComponentes(componentes);
  }

  // Muestra una lista de componentes en formato tabular
  void mostrarComponentes(const vector<IComponente *> &componentes) {
    if (componentes.empty()) {
      cout << "No se encontraron componentes\n";
      return;
    }

    // Configurar formato de salida para precios
    cout << fixed << setprecision(2);
    for (const auto *c : componentes) {
      cout << c->getCodigo() << " | " << c->getNombre() << " | $"
                << c->calcularPrecioVenta() << " | Stock: " << c->getCantidad()
                << " | " << c->getTipo() << endl;
    }
  }
};

// Función principal que inicia la aplicación del almacén
int main() {
  // Crear la interfaz de usuario y ejecutar el sistema
  AlmacenUI app;
  app.ejecutar();
  return 0;
}
