# Sistema de Inventario - Stock Mínimo

## Descripción
Sistema de gestión de inventario que mantiene productos en lista doblemente enlazada y identifica productos con stock bajo (< 5 unidades).

## Funcionalidades Implementadas

### a) Insertar productos con datos completos ✅
- Código, nombre y cantidad
- Lista doblemente enlazada
- Validación de datos

### b) Mostrar productos con stock < 5 unidades ✅
- Filtrado automático por stock mínimo
- Presentación tabular
- Arreglos estáticos

### c) Actualizar stock por código ✅
- Búsqueda por código de producto
- Actualización de cantidad
- Validación de existencia

### d) Medición de tiempos ✅
- Tiempo de inserción
- Tiempo de consulta stock bajo
- Tiempo de actualización
- Tiempo total del programa

## Arquitectura Implementada

### Capas
- **ProductRepository**: Lista doblemente enlazada
- **ProductService**: Lógica de negocio y validaciones
- **ProductController**: Intermediario puro
- **ProductView**: Manejo completo de UI

### Principios SOLID
- **S**: Responsabilidad única por capa
- **O**: Extensible mediante interfaces
- **L**: Sustitución de interfaces
- **I**: Interfaces segregadas
- **D**: Inversión de dependencias

## Estructuras de Datos

### Product
```cpp
struct Product {
    std::string code;
    std::string name;
    int quantity;
    Product* next;
    Product* prev;
};
```

### ProductArray (Arreglo Estático)
```cpp
struct ProductArray {
    Product* products[MAX_PRODUCTS];
    int count;
};
```

## Compilación y Ejecución

```bash
make          # Compilar programa principal
make run      # Ejecutar programa interactivo
make demo     # Compilar y ejecutar demostración
make clean    # Limpiar archivos
```

## Complejidad Temporal
- **Inserción**: O(1) - al final de la lista
- **Stock bajo**: O(n) - recorre toda la lista
- **Actualización**: O(n) - busca por código
- **Espacio**: O(1) - arreglos estáticos