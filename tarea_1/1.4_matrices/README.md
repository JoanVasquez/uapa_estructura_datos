# Sistema de Reasignación Óptima de Productos

## Arquitectura Profesional

### Principios SOLID Aplicados

- **S** - Single Responsibility: Cada clase tiene responsabilidad específica
- **O** - Open/Closed: Extensible mediante interfaces (IOptimizador)
- **L** - Liskov Substitution: Diferentes algoritmos intercambiables
- **I** - Interface Segregation: Interfaces cohesivas y específicas
- **D** - Dependency Inversion: Servicio depende de abstracciones

### Patrones de Diseño

- **Strategy Pattern**: Diferentes algoritmos de optimización
- **Dependency Injection**: Inyección de optimizador en servicio
- **Value Object**: Movimiento como objeto inmutable
- **Template Method**: Estructura común de optimización

## Implementaciones

### C++ (cpp/)
```
cpp/
├── include/
│   ├── Movimiento.h           # Estructura de datos
│   ├── IOptimizador.h         # Interfaz optimizador
│   ├── OptimizadorGreedy.h    # Algoritmo greedy
│   └── RedistribucionService.h # Servicio aplicación
├── src/
│   ├── OptimizadorGreedy.cpp
│   ├── RedistribucionService.cpp
│   └── main.cpp
└── Makefile
```

### Python (python/)
```
python/
├── movimiento.py              # Dataclass movimiento
├── optimizador_base.py        # ABC optimizador
├── optimizador_greedy.py      # Implementación greedy
├── redistribucion_service.py  # Servicio aplicación
└── main.py                    # Programa principal
```

## Algoritmo de Optimización

### Estrategia Greedy
1. **Para cada producto** y **almacén destino**:
   - Calcula faltante = umbral - stock_actual
   - Busca almacén origen con menor distancia
   - Mueve cantidad mínima necesaria
   - Actualiza costos y registra movimiento

### Restricciones Implementadas
- ✅ No mover más de lo disponible
- ✅ Solo productos del mismo tipo
- ✅ Costo = cantidad × distancia[origen][destino]
- ✅ Mantener umbrales mínimos

## Funcionalidades

### Entrada
- **Matriz stock[6][15]**: Inventario actual
- **Matriz distancia[6][6]**: Costos de transporte
- **Array umbral[15]**: Mínimos por producto

### Salida
- **Lista de movimientos** con detalles completos
- **Costo total** de redistribución
- **Número de movimientos** realizados

### Formato de Salida
```
Producto 7: 10 unidades movidas de Almacén 0 a Almacén 3. Costo: 70
Producto 12: 5 unidades movidas de Almacén 5 a Almacén 2. Costo: 25
Total de movimientos realizados: 2
Costo total: 95
```

## Compilación y Uso

### C++
```bash
cd cpp/
make                    # Compilar
./redistribucion       # Ejecutar
make clean             # Limpiar
```

### Python
```bash
cd python/
python3 main.py        # Ejecutar directamente
```

## Características Técnicas

### C++
- **std::array** para matrices de tamaño fijo
- **Smart pointers** para gestión de memoria
- **Validaciones robustas** con excepciones
- **Algoritmos STL** para optimización

### Python
- **Type hints** para claridad de código
- **Dataclasses** para estructuras inmutables
- **ABC** para interfaces abstractas
- **List comprehensions** para eficiencia

## Manejo de Errores

- Validación de dimensiones de matrices
- Prevención de valores negativos
- Verificación de disponibilidad de stock
- Manejo de casos sin solución óptima

## Datos de Prueba

Ambas implementaciones incluyen datos de prueba que demuestran:
- Redistribución entre almacenes con exceso/déficit
- Cálculo de costos basado en distancias
- Optimización greedy para minimizar costos totales