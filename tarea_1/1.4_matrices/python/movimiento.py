from dataclasses import dataclass

@dataclass
class Movimiento:
    producto: int
    origen: int
    destino: int
    cantidad: int
    costo: int
    
    def __str__(self):
        return (f"Producto {self.producto}: {self.cantidad} unidades movidas "
                f"de Almacén {self.origen} a Almacén {self.destino}. "
                f"Costo: {self.costo}")