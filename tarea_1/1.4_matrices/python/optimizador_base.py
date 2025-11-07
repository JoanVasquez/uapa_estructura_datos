from abc import ABC, abstractmethod
from typing import List
from movimiento import Movimiento

class IOptimizador(ABC):
    @abstractmethod
    def optimizar(self) -> List[Movimiento]:
        pass
    
    @abstractmethod
    def configurar_stock(self, stock: List[List[int]]) -> None:
        pass
    
    @abstractmethod
    def configurar_distancias(self, distancias: List[List[int]]) -> None:
        pass
    
    @abstractmethod
    def configurar_umbrales(self, umbrales: List[int]) -> None:
        pass
    
    @abstractmethod
    def obtener_costo_total(self) -> int:
        pass