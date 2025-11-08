# Sistema de Gestión de Almacén de Componentes Electrónicos

## Arquitectura Profesional

### Principios SOLID Aplicados

- **S** - Single Responsibility: Cada clase tiene una responsabilidad específica
- **O** - Open/Closed: Extensible mediante herencia sin modificar código existente
- **L** - Liskov Substitution: ComponenteNacional e ComponenteImportado son intercambiables
- **I** - Interface Segregation: Interfaces específicas y cohesivas
- **D** - Dependency Inversion: Dependencias hacia abstracciones, no implementaciones

### Patrones de Diseño

- **Template Method**: ComponenteBase define estructura común
- **Strategy**: Diferentes algoritmos de cálculo de precio
- **Repository**: Abstracción de persistencia de datos
- **Dependency Injection**: Inyección de dependencias en AlmacenService

### Arquitectura MVC

```
UI Layer (main.cpp)
    ↓
Controller Layer (AlmacenController)
    ↓
Service Layer (AlmacenService)
    ↓
Repository Layer (AlmacenRepository)
```

### Estructura del Proyecto

```
include/          # Headers/Interfaces
├── IComponente.h           # Interfaz base
├── IAlmacenRepository.h    # Abstracción repositorio
├── ComponenteBase.h        # Clase base abstracta
├── ComponenteNacional.h    # Componente nacional
├── ComponenteImportado.h   # Componente importado
├── AlmacenRepository.h     # Implementación repositorio
├── AlmacenService.h        # Servicio de aplicación
└── AlmacenController.h     # Controller MVC

src/              # Implementaciones
├── ComponenteBase.cpp
├── ComponenteNacional.cpp
├── ComponenteImportado.cpp
├── AlmacenRepository.cpp
├── AlmacenService.cpp
├── AlmacenController.cpp   # Coordinación UI-Service
└── main.cpp               # UI con patrón MVC
```

### Funcionalidades

1. **Registrar componentes** (nacionales/importados)
2. **Modificar existencias** y niveles mínimos
3. **Listar nacionales** por precio mínimo
4. **Listar importados** por país
5. **Detectar stock bajo** automáticamente

### Cálculo de Precios

- **Nacionales**: Costo + 5%
- **Importados**: Costo + 5% + (27 × Precio USD)

### Compilación y Uso

```bash
make            # Compilar
./almacen       # Ejecutar
make clean      # Limpiar
```

### Características Técnicas

- **Patrón MVC**: Separación clara de responsabilidades
- **using namespace std**: Código más legible
- **Comentarios explicativos**: Documentación en español
- **Validación robusta**: Excepciones específicas
- **Smart pointers**: Gestión segura de memoria
- **Dependency Injection**: Controllers reciben services