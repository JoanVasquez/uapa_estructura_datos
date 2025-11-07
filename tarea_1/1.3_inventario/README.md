# Sistema de Control de Inventario Multi-Sucursal

## Arquitectura Profesional

### Principios SOLID Aplicados

- **S** - Single Responsibility: Cada clase tiene responsabilidad específica
- **O** - Open/Closed: Extensible mediante interfaces
- **L** - Liskov Substitution: IInventario permite intercambiabilidad
- **I** - Interface Segregation: Interfaces cohesivas (IInventario, IInventarioService)
- **D** - Dependency Inversion: Servicio depende de abstracciones

### Patrones de Diseño

- **Dependency Injection**: InventarioService recibe IInventario
- **Strategy Pattern**: Diferentes algoritmos de cálculo implícitos
- **Template Method**: Estructura común en validaciones
- **Value Object**: AlertaStock como objeto de valor

### Estructura del Proyecto

```
include/                      # Headers/Interfaces
├── IInventario.h            # Interfaz inventario
├── IInventarioService.h     # Interfaz servicio
├── Almacen.h               # Implementación matriz stock[6][15]
└── InventarioService.h     # Servicio de aplicación

src/                        # Implementaciones
├── Almacen.cpp
├── InventarioService.cpp
└── main.cpp               # UI y punto de entrada
```

### Funcionalidades Core

1. **Registrar existencias** por producto y almacén
2. **Detectar productos agotados** por sucursal
3. **Identificar almacén** con menor stock total
4. **Emitir alertas** por debajo de umbral configurable

### Características Técnicas

- **Matriz bidimensional** stock[6][15] usando std::array
- **6 almacenes**, **15 productos** máximo
- **Umbral configurable** para alertas
- **Validaciones robustas** con excepciones específicas
- **Interfaz intuitiva** con emojis y mensajes claros

### Estructura de Datos

```cpp
std::array<std::array<int, 15>, 6> stock;  // [almacén][producto]
```

### Casos de Uso

- ✅ **Registro de stock**: Actualización por almacén/producto
- ✅ **Detección de agotados**: Productos con stock = 0
- ✅ **Almacén crítico**: Menor stock total entre sucursales
- ✅ **Sistema de alertas**: Stock < umbral mínimo
- ✅ **Configuración flexible**: Umbral ajustable

### Compilación y Uso

```bash
make            # Compilar
./inventario    # Ejecutar
make clean      # Limpiar
```

### Manejo de Errores

- Validación de rangos (almacén 0-5, producto 0-14)
- Prevención de valores negativos
- Excepciones específicas con mensajes descriptivos
- Validación de entrada en UI

### Datos de Prueba

El sistema incluye opción para cargar datos de prueba que demuestran:
- Stock normal, bajo y agotado
- Diferentes niveles por almacén
- Generación automática de alertas