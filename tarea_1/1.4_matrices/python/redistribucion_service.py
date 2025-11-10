from typing import List
from optimizador_base import IOptimizador

class RedistribucionService:
    def __init__(self, optimizador: IOptimizador):
        self.optimizador = optimizador
    
    def ejecutar_optimizacion(self) -> None:
        movimientos = self.optimizador.optimizar()
        
        if not movimientos:
            print("✅ No se requieren movimientos de redistribución")
            return
        
        print("\n=== RESULTADOS DE REDISTRIBUCIÓN ===")
        for mov in movimientos:
            print(mov)
        
        print(f"Total de movimientos realizados: {len(movimientos)}")
        print(f"Costo total: {self.optimizador.obtener_costo_total()}")
    
    def mostrar_resultados(self) -> None:
        print(f"\n📊 Optimización completada")
        print(f"💰 Costo total: {self.optimizador.obtener_costo_total()}")
    
    def cargar_datos_prueba(self) -> None:
        # Stock inicial
        stock = [[0] * 15 for _ in range(6)]
        stock[0][7] = 25   # Almacén 0, Producto 7: exceso
        stock[3][7] = 2    # Almacén 3, Producto 7: déficit
        stock[5][12] = 20  # Almacén 5, Producto 12: exceso
        stock[2][12] = 3   # Almacén 2, Producto 12: déficit
        
        # Distancias
        distancias = [[1 if i != j else 0 for j in range(6)] for i in range(6)]
        distancias[0][3] = 7
        distancias[5][2] = 5
        
        # Umbrales
        umbrales = [5] * 15
        umbrales[7] = 10
        umbrales[12] = 8
        
        self.optimizador.configurar_stock(stock)
        self.optimizador.configurar_distancias(distancias)
        self.optimizador.configurar_umbrales(umbrales)
        
        print("✅ Datos de prueba cargados exitosamente")
    
    def configurar_matrices(self) -> None:
        try:
            print("Configurando stock (ingrese valores separados por espacios):")
            stock = []
            for a in range(6):
                print(f"Almacén {a} (15 productos): ", end="")
                entrada = input().strip()
                if entrada:
                    fila = list(map(int, entrada.split()))
                    if len(fila) != 15:
                        fila = fila[:15] + [0] * (15 - len(fila))
                else:
                    fila = [0] * 15
                stock.append(fila)
            
            print("Configurando distancias:")
            distancias = []
            for i in range(6):
                print(f"Distancias desde almacén {i}: ", end="")
                fila = list(map(int, input().split()))
                if len(fila) != 6:
                    fila = fila[:6] + [1] * (6 - len(fila))
                distancias.append(fila)
            
            print("Configurando umbrales (15 productos): ", end="")
            umbrales = list(map(int, input().split()))
            if len(umbrales) != 15:
                umbrales = umbrales[:15] + [5] * (15 - len(umbrales))
            
            self.optimizador.configurar_stock(stock)
            self.optimizador.configurar_distancias(distancias)
            self.optimizador.configurar_umbrales(umbrales)
            
            print("✅ Configuración completada")
            
        except ValueError as e:
            print(f"❌ Error en configuración: {e}")
        except Exception as e:
            print(f"❌ Error inesperado: {e}")