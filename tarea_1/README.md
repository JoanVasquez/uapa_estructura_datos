# Estructura de Datos - Tarea 1

Implementaciones profesionales de sistemas de gestión usando principios SOLID, Clean Code y patrón MVC.

## Proyectos Implementados

### 1.1 Almacén de Componentes Electrónicos 🏢
Sistema de gestión de inventario con componentes nacionales e importados.

**Características:**
- Patrón MVC con AlmacenController
- Herencia polimórfica (ComponenteNacional/ComponenteImportado)
- Cálculo automático de precios de venta
- Repository pattern con filtros avanzados

**Uso:**
```bash
cd 1.1_almacen && make && ./almacen
```

### 1.2 Sistema Académico 🎓
Gestión de calificaciones de estudiantes con 5 evaluaciones.

**Características:**
- AcademiaController coordinando operaciones
- Arreglo unidimensional de objetos Estudiante
- Cálculo automático de promedio y estado
- Filtrado de aprobados (≥70) y ordenamiento

**Uso:**
```bash
cd 1.2_bootcamp && make && ./academia
```

### 1.3 Control de Inventario Multi-Sucursal 📦
Sistema de inventario para 6 almacenes con 15 productos cada uno.

**Características:**
- InventarioController con matriz bidimensional stock[6][15]
- Detección de productos agotados por sucursal
- Identificación de almacén crítico
- Sistema de alertas configurable

**Uso:**
```bash
cd 1.3_inventario && make && ./inventario
```

### 1.4 Reasignación Óptima de Productos 🚚
Algoritmo de redistribución entre almacenes minimizando costos.

**Características:**
- RedistribucionController en C++ y Python
- Algoritmo greedy de optimización
- Matriz de distancias para costos de transporte
- Respeto a umbrales mínimos por producto

**Uso:**
```bash
# C++
cd 1.4_matrices/cpp && make && ./redistribucion

# Python
cd 1.4_matrices/python && python3 main.py
```

## Arquitectura Profesional

### Patrón MVC Implementado 🏢
- **Model**: Entidades de dominio (Componente, Estudiante, etc.)
- **View**: Interfaz de usuario (UI classes)
- **Controller**: Coordinación entre UI y Service

### Principios SOLID ✅
- **S**ingle Responsibility: Cada clase tiene una responsabilidad única
- **O**pen/Closed: Extensible mediante interfaces
- **L**iskov Substitution: Intercambiabilidad de implementaciones
- **I**nterface Segregation: Interfaces cohesivas y específicas
- **D**ependency Inversion: Dependencias hacia abstracciones

### Patrones Implementados
- **MVC Pattern**: Separación UI-Controller-Service
- **Repository Pattern**: Abstracción de persistencia
- **Factory Pattern**: Creación de objetos
- **Strategy Pattern**: Algoritmos intercambiables
- **Dependency Injection**: Inyección de dependencias

### Características Técnicas
- **Arquitectura en capas**: UI → Controller → Service → Repository
- **Manejo robusto de errores** con excepciones específicas
- **Validaciones de entrada** en todas las capas
- **Smart pointers** (C++) para gestión segura de memoria
- **Type hints** (Python) para claridad de código
- **using namespace std** para legibilidad
- **Comentarios explicativos** en todas las funciones

## Estructura del Proyecto

```
tarea_1/
├── 1.1_almacen/           # Componentes electrónicos
│   ├── include/           # Headers (Interfaces, Controllers, Services)
│   ├── src/              # Implementaciones con MVC
│   └── Makefile
├── 1.2_bootcamp/         # Sistema académico
│   ├── include/           # Arquitectura MVC
│   ├── src/              # Controllers + Services
│   └── Makefile
├── 1.3_inventario/       # Inventario multi-sucursal
│   ├── include/           # Patrón MVC completo
│   ├── src/              # Separación de responsabilidades
│   └── Makefile
├── 1.4_matrices/         # Reasignación óptima
│   ├── cpp/              # MVC en C++
│   └── python/           # MVC en Python
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

- **C++14/17** con STL y using namespace std
- **Python 3.8+** con type hints y MVC
- **Make** para compilación automatizada
- **Arquitectura MVC** con separación de capas
- **Comentarios explicativos** en español