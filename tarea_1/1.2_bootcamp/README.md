# Sistema de Gestión Académica

## Arquitectura Profesional

### Principios SOLID Aplicados

- **S** - Single Responsibility: Cada clase tiene una responsabilidad específica
- **O** - Open/Closed: Extensible mediante interfaces sin modificar código
- **L** - Liskov Substitution: IEstudiante permite intercambiabilidad
- **I** - Interface Segregation: Interfaces cohesivas y específicas
- **D** - Dependency Inversion: Dependencias hacia abstracciones

### Patrones de Diseño

- **Repository Pattern**: Abstracción de persistencia
- **Dependency Injection**: Inyección en AcademiaService
- **Template Method**: Estructura común en validaciones
- **Strategy**: Diferentes algoritmos de ordenamiento

### Arquitectura MVC

```
UI Layer (main.cpp)
    ↓
Controller Layer (AcademiaController)
    ↓
Service Layer (AcademiaService)
    ↓
Repository Layer (AcademiaRepository)
```

### Estructura del Proyecto

```
include/                    # Headers/Interfaces
├── IEstudiante.h          # Interfaz estudiante
├── IAcademiaRepository.h   # Abstracción repositorio
├── Estudiante.h           # Implementación estudiante
├── AcademiaRepository.h   # Repositorio concreto
├── AcademiaService.h      # Servicio de aplicación
└── AcademiaController.h   # Controller MVC

src/                       # Implementaciones
├── Estudiante.cpp
├── AcademiaRepository.cpp
├── AcademiaService.cpp
├── AcademiaController.cpp # Coordinación UI-Service
└── main.cpp              # UI con patrón MVC
```

### Funcionalidades

1. **Registrar estudiantes** con validación
2. **Registrar calificaciones** (5 evaluaciones)
3. **Cálculo automático** de promedio y estado
4. **Filtrar aprobados** (≥ 70)
5. **Ordenamiento** por promedio descendente

### Características Técnicas

- **Arreglo unidimensional** de objetos Estudiante
- **std::array<double, 5>** para calificaciones
- **Smart pointers** para gestión de memoria
- **Algoritmos STL** para ordenamiento y filtrado
- **Validaciones robustas** con excepciones

### Compilación y Uso

```bash
make            # Compilar
./academia      # Ejecutar
make clean      # Limpiar
```

### Características Técnicas

- **Patrón MVC**: UI → Controller → Service → Repository
- **using namespace std**: Sintaxis simplificada
- **Comentarios explicativos**: Documentación detallada
- **Validación completa**: Rangos, duplicados, tipos
- **STL algorithms**: Ordenamiento y filtrado eficiente
- **Dependency Injection**: Arquitectura desacoplada