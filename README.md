# Estructura de Datos - Tarea 1

Implementaciones profesionales de sistemas de gestión usando principios SOLID, Clean Code y patrones de diseño.

## Proyectos Implementados

### 1.1 Almacén de Componentes Electrónicos 🏢
Sistema de gestión de inventario con componentes nacionales e importados.

**Características:**
- Herencia polimórfica (ComponenteNacional/ComponenteImportado)
- Cálculo automático de precios de venta
- Repository pattern con filtros avanzados
- Factory pattern para creación de objetos

**Uso:**
```bash
cd 1.1_almacen && make && ./almacen
```

### 1.2 Sistema Académico 🎓
Gestión de calificaciones de estudiantes con 5 evaluaciones.

**Características:**
- Arreglo unidimensional de objetos Estudiante
- Cálculo automático de promedio y estado
- Filtrado de aprobados (≥70)
- Ordenamiento por promedio

**Uso:**
```bash
cd 1.2_bootcamp && make && ./academia
```

### 1.3 Control de Inventario Multi-Sucursal 📦
Sistema de inventario para 6 almacenes con 15 productos cada uno.

**Características:**
- Matriz bidimensional stock[6][15]
- Detección de productos agotados
- Identificación de almacén crítico
- Sistema de alertas configurable

**Uso:**
```bash
cd 1.3_inventario && make && ./inventario
```

### 1.4 Reasignación Óptima de Productos 🚚
Algoritmo de redistribución entre almacenes minimizando costos.

**Características:**
- Implementado en C++ y Python
- Algoritmo greedy de optimización
- Matriz de distancias para costos
- Respeto a umbrales mínimos

**Uso:**
```bash
# C++
cd 1.4_matrices/cpp && make && ./redistribucion

# Python
cd 1.4_matrices/python && python3 main.py
```

## Arquitectura Profesional

### Principios SOLID ✅
- **S**ingle Responsibility
- **O**pen/Closed
- **L**iskov Substitution
- **I**nterface Segregation
- **D**ependency Inversion

### Patrones Implementados
- Repository Pattern
- Factory Pattern
- Strategy Pattern
- Dependency Injection
- Template Method

### Características Técnicas
- Manejo robusto de errores
- Validaciones de entrada
- Smart pointers (C++)
- Type hints (Python)
- Código limpio y mantenible

## Estructura del Proyecto

```
tarea_1/
├── 1.1_almacen/           # Componentes electrónicos
│   ├── include/           # Headers
│   ├── src/              # Implementaciones
│   └── Makefile
├── 1.2_bootcamp/         # Sistema académico
│   ├── include/
│   ├── src/
│   └── Makefile
├── 1.3_inventario/       # Inventario multi-sucursal
│   ├── include/
│   ├── src/
│   └── Makefile
├── 1.4_matrices/         # Reasignación óptima
│   ├── cpp/              # Implementación C++
│   └── python/           # Implementación Python
├── .gitignore
└── README.md
```

## Compilación Global

```bash
# Compilar todos los proyectos C++
for dir in 1.1_almacen 1.2_bootcamp 1.3_inventario 1.4_matrices/cpp; do
    cd $dir && make && cd ..
done
```

## Tecnologías Utilizadas

- **C++14/17** con STL
- **Python 3.8+** con type hints
- **Make** para compilación
- **Arquitectura limpia** con separación de capas