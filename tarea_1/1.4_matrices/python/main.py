#!/usr/bin/env python3

from optimizador_greedy import OptimizadorGreedy
from redistribucion_service import RedistribucionService

class RedistribucionUI:
    def __init__(self):
        optimizador = OptimizadorGreedy()
        self.service = RedistribucionService(optimizador)
    
    def ejecutar(self):
        while True:
            self.mostrar_menu()
            try:
                opcion = int(input("Opción: "))
                if opcion == 0:
                    print("👋 Saliendo del sistema...")
                    break
                self.procesar_opcion(opcion)
            except ValueError:
                print("❌ Entrada inválida. Ingrese un número.")
            except Exception as e:
                print(f"❌ Error: {e}")
    
    def mostrar_menu(self):
        print("\n=== REASIGNACIÓN ÓPTIMA DE PRODUCTOS ===")
        print("1. Configurar matrices manualmente")
        print("2. Cargar datos de prueba")
        print("3. Ejecutar optimización")
        print("4. Mostrar resultados")
        print("0. Salir")
    
    def procesar_opcion(self, opcion: int):
        if opcion == 1:
            self.service.configurar_matrices()
        elif opcion == 2:
            self.service.cargar_datos_prueba()
        elif opcion == 3:
            self.service.ejecutar_optimizacion()
        elif opcion == 4:
            self.service.mostrar_resultados()
        else:
            print("❌ Opción inválida")

def main():
    print("🚚 Sistema de Reasignación Óptima de Productos (Python)")
    
    app = RedistribucionUI()
    app.ejecutar()

if __name__ == "__main__":
    main()