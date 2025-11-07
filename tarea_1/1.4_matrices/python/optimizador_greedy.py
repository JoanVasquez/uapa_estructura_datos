from typing import List, Optional
from optimizador_base import IOptimizador
from movimiento import Movimiento

class OptimizadorGreedy(IOptimizador):
    NUM_ALMACENES = 6
    NUM_PRODUCTOS = 15
    
    def __init__(self):
        self.stock = [[0] * self.NUM_PRODUCTOS for _ in range(self.NUM_ALMACENES)]
        self.distancias = [[1] * self.NUM_ALMACENES for _ in range(self.NUM_ALMACENES)]
        self.umbrales = [5] * self.NUM_PRODUCTOS
        self.movimientos = []
        self.costo_total = 0
        
        # Diagonal de distancias = 0
        for i in range(self.NUM_ALMACENES):
            self.distancias[i][i] = 0
    
    def configurar_stock(self, stock: List[List[int]]) -> None:
        if len(stock) != self.NUM_ALMACENES or any(len(row) != self.NUM_PRODUCTOS for row in stock):
            raise ValueError("Dimensiones de stock incorrectas")
        self.stock = [row[:] for row in stock]
    
    def configurar_distancias(self, distancias: List[List[int]]) -> None:
        if len(distancias) != self.NUM_ALMACENES or any(len(row) != self.NUM_ALMACENES for row in distancias):
            raise ValueError("Dimensiones de distancias incorrectas")
        if any(dist < 0 for row in distancias for dist in row):
            raise ValueError("Las distancias no pueden ser negativas")
        self.distancias = [row[:] for row in distancias]
    
    def configurar_umbrales(self, umbrales: List[int]) -> None:
        if len(umbrales) != self.NUM_PRODUCTOS:
            raise ValueError("Número de umbrales incorrecto")
        self.umbrales = umbrales[:]
    
    def optimizar(self) -> List[Movimiento]:
        self.movimientos = []
        self.costo_total = 0
        
        for producto in range(self.NUM_PRODUCTOS):
            for destino in range(self.NUM_ALMACENES):
                faltante = self.umbrales[producto] - self.stock[destino][producto]
                
                while faltante > 0:
                    origen = self._encontrar_mejor_origen(producto, destino)
                    if origen is None:
                        break
                    
                    disponible = self.stock[origen][producto] - self.umbrales[producto]
                    if disponible <= 0:
                        break
                    
                    cantidad = min(faltante, disponible)
                    self._realizar_movimiento(producto, origen, destino, cantidad)
                    faltante -= cantidad
        
        return self.movimientos
    
    def _encontrar_mejor_origen(self, producto: int, destino: int) -> Optional[int]:
        mejor_origen = None
        menor_costo = float('inf')
        
        for origen in range(self.NUM_ALMACENES):
            if (origen != destino and 
                self.stock[origen][producto] > self.umbrales[producto] and
                self.distancias[origen][destino] < menor_costo):
                menor_costo = self.distancias[origen][destino]
                mejor_origen = origen
        
        return mejor_origen
    
    def _realizar_movimiento(self, producto: int, origen: int, destino: int, cantidad: int) -> None:
        self.stock[origen][producto] -= cantidad
        self.stock[destino][producto] += cantidad
        
        costo = cantidad * self.distancias[origen][destino]
        self.costo_total += costo
        
        self.movimientos.append(Movimiento(producto, origen, destino, cantidad, costo))
    
    def obtener_costo_total(self) -> int:
        return self.costo_total