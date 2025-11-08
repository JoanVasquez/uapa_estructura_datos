from redistribucion_service import RedistribucionService

class RedistribucionController:
    def __init__(self, service: RedistribucionService):
        self.service = service
    
    def ejecutar_optimizacion(self) -> None:
        self.service.ejecutar_optimizacion()
    
    def mostrar_resultados(self) -> None:
        self.service.mostrar_resultados()
    
    def cargar_datos_prueba(self) -> None:
        self.service.cargar_datos_prueba()
    
    def configurar_matrices(self) -> None:
        self.service.configurar_matrices()