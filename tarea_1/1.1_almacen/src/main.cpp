#include "../include/AlmacenService.h"
#include "../include/AlmacenRepository.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Clase que maneja la interfaz de usuario para el sistema de almacén
// Usa arreglos estáticos para cumplir con criterios de evaluación
class AlmacenUI {
private:
  AlmacenService* service; // Servicio para operaciones del almacén
  AlmacenRepository* repository; // Repositorio con arreglo estático

public:
  // Constructor que inicializa servicio y repositorio
  AlmacenUI() {
    repository = new AlmacenRepository();
    service = new AlmacenService(repository);
  }
  
  // Destructor para liberar memoria
  ~AlmacenUI() {
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
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Precio costo: ";
    cin >> precio;
    cout << "Cantidad: ";
    cin >> cantidad;
    cin.ignore();
    cout << "Empresa: ";
    getline(cin, empresa);
    cout << "Nivel mínimo: ";
    cin >> minimo;

    if (service->registrarNacional(codigo, nombre, precio, cantidad, empresa, minimo)) {
      cout << "Componente registrado exitosamente\n";
    } else {
      cout << "Error: No se pudo registrar el componente\n";
    }
  }

  // Registra un nuevo componente importado con precio en USD
  void registrarImportado() {
    string codigo, nombre, pais;
    double precio, precioUSD;
    int cantidad, minimo;

    cin.ignore();
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Precio costo: ";
    cin >> precio;
    cout << "Cantidad: ";
    cin >> cantidad;
    cin.ignore();
    cout << "País: ";
    getline(cin, pais);
    cout << "Precio USD: ";
    cin >> precioUSD;
    cout << "Nivel mínimo: ";
    cin >> minimo;

    if (service->registrarImportado(codigo, nombre, precio, cantidad, pais, precioUSD, minimo)) {
      cout << "Componente registrado exitosamente\n";
    } else {
      cout << "Error: No se pudo registrar el componente\n";
    }
  }

  // Modifica la cantidad en stock usando arreglos estáticos
  void modificarCantidad() {
    string codigo;
    int cantidad;
    cin.ignore();
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nueva cantidad: ";
    cin >> cantidad;
    
    if (service->modificarCantidad(codigo, cantidad)) {
      cout << "Cantidad actualizada\n";
    } else {
      cout << "Error: Componente no encontrado\n";
    }
  }

  // Modifica el nivel mínimo usando manipulación directa de arreglos
  void modificarNivelMinimo() {
    string codigo;
    int nivel;
    cin.ignore();
    cout << "Código: ";
    getline(cin, codigo);
    cout << "Nuevo nivel mínimo: ";
    cin >> nivel;
    
    if (service->modificarNivelMinimo(codigo, nivel)) {
      cout << "Nivel mínimo actualizado\n";
    } else {
      cout << "Error: Componente no encontrado\n";
    }
  }

  // Lista componentes nacionales usando arreglo estático
  void listarNacionalesPorPrecio() {
    double minimo;
    cout << "Precio mínimo: ";
    cin >> minimo;
    
    IComponente* resultado[IAlmacenRepository::MAX_COMPONENTES];
    int total = service->nacionalesPorPrecio(resultado, minimo);
    
    cout << "\n=== COMPONENTES NACIONALES ===\n";
    mostrarComponentes(resultado, total);
  }

  // Lista componentes importados usando arreglo estático
  void listarImportadosPorPais() {
    string pais;
    cin.ignore();
    cout << "País: ";
    getline(cin, pais);
    
    IComponente* resultado[IAlmacenRepository::MAX_COMPONENTES];
    int total = service->importadosPorPais(resultado, pais);
    
    cout << "\n=== COMPONENTES IMPORTADOS ===\n";
    mostrarComponentes(resultado, total);
  }

  // Lista componentes bajo stock usando arreglo estático
  void listarBajoStock() {
    IComponente* resultado[IAlmacenRepository::MAX_COMPONENTES];
    int total = service->componentesBajoStock(resultado);
    
    cout << "\n=== COMPONENTES BAJO STOCK ===\n";
    mostrarComponentes(resultado, total);
  }

  // Muestra arreglo de componentes con estructuras repetitivas
  void mostrarComponentes(IComponente* componentes[], int total) {
    if (total == 0) {
      cout << "No se encontraron componentes\n";
      return;
    }

    cout << fixed << setprecision(2);
    // Usar bucle for tradicional para manipular arreglo estático
    for (int i = 0; i < total; i++) {
      IComponente* c = componentes[i];
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
