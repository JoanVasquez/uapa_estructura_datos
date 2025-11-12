# Estructura de Datos - Tarea 1

Implementaciones profesionales de sistemas de gestion usando principios SOLID, Clean Code y patron MVC.

## Proyectos Implementados

### 1.1 Almacen de Componentes Electronicos 🏢
Sistema de gestion de inventario con componentes nacionales e importados.

**Características:**
- Patrón MVC con AlmacenController
- Herencia polimórfica (ComponenteNacional/ComponenteImportado)
- Cálculo automático de precios de venta
- Repository pattern con filtros avanzados

**Uso:**
```bash
cd 1.1_almacen && make && ./almacen
```

### 1.2 Sistema Academico 🎓
Gestion de calificaciones de estudiantes con 5 evaluaciones.

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

### 1.4 Reasignacion Optima de Productos 🚚
Algoritmo de redistribucion entre almacenes minimizando costos.

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

### Patron MVC Implementado 🏢
- **Model**: Entidades de dominio (Componente, Estudiante, etc.)
- **View**: Interfaz de usuario (UI classes)
- **Controller**: Coordinacion entre UI y Service

### Principios SOLID ✅
- **S**ingle Responsibility: Cada clase tiene una responsabilidad unica
- **O**pen/Closed: Extensible mediante interfaces
- **L**iskov Substitution: Intercambiabilidad de implementaciones
- **I**nterface Segregation: Interfaces cohesivas y especificas
- **D**ependency Inversion: Dependencias hacia abstracciones

### Patrones Implementados
- **MVC Pattern**: Separacion UI-Controller-Service
- **Repository Pattern**: Abstraccion de persistencia
- **Factory Pattern**: Creacion de objetos
- **Strategy Pattern**: Algoritmos intercambiables
- **Dependency Injection**: Inyeccion de dependencias

### Características Técnicas
- **Arquitectura en capas**: UI → Controller → Service → Repository
- **Manejo robusto de errores** con excepciones especificas
- **Validaciones de entrada** en todas las capas
- **Smart pointers** (C++) para gestion segura de memoria
- **Type hints** (Python) para claridad de codigo
- **using namespace std** para legibilidad
- **Comentarios explicativos** en todas las funciones

## Estructura del Proyecto

```
tarea_1/
├── 1.1_almacen/           # Componentes electronicos
│   ├── include/           # Headers (Interfaces, Controllers, Services)
│   ├── src/              # Implementaciones con MVC
│   ├── Makefile          # Linux/macOS
│   └── Makefile.win      # Windows
├── 1.2_bootcamp/         # Sistema academico
│   ├── include/           # Arquitectura MVC
│   ├── src/              # Controllers + Services
│   ├── Makefile          # Linux/macOS
│   └── Makefile.win      # Windows
├── 1.3_inventario/       # Inventario multi-sucursal
│   ├── include/           # Patron MVC completo
│   ├── src/              # Separacion de responsabilidades
│   ├── Makefile          # Linux/macOS
│   └── Makefile.win      # Windows
├── compile_all.sh        # Script Linux/macOS
├── compile_all.bat       # Script Windows
├── .gitignore
└── README.md
```

## Compilacion

### Linux/macOS
```bash
bash compile_all.sh
```

### Windows
```cmd
compile_all.bat
```

## Tecnologías Utilizadas

- **C++14/17** con STL y using namespace std
- **Python 3.8+** con type hints y MVC
- **Make** para compilacion automatizada
- **Arquitectura MVC** con separacion de capas
- **Sin acentos** para compatibilidad multiplataforma