# Documentación Técnica - Sistema de Tareas Priorizadas

## Cumplimiento de Criterios

### 1. Definición correcta de estructuras de datos ✅
- **Task**: Estructura que representa una tarea con nombre, prioridad, estado y punteros next/prev
- **Lista doblemente enlazada**: Implementada en TaskRepository con punteros head y tail
- **Enum TaskStatus**: Define estados PENDING y COMPLETED

### 2. Implementación con listas enlazadas ✅
- **Lista doblemente enlazada**: Cada nodo tiene punteros next y prev
- **Inserción ordenada**: Las tareas se insertan manteniendo orden descendente por prioridad
- **Navegación bidireccional**: Permite recorrido hacia adelante y atrás

### 3. Codificación funcional ✅
- Compilación exitosa con g++ y estándar C++17
- Makefile incluido para facilitar compilación
- Programa de demostración que muestra todas las funcionalidades

### 4. Uso de estructuras repetitivas ✅
- **Bucles while**: Para recorrer la lista en inserción, búsqueda y eliminación
- **Bucle do-while**: En el menú principal para repetir hasta que el usuario salga
- **Condicionales anidadas**: En la función de inserción para determinar posición correcta

### 5. Uso apropiado de punteros ✅
- **Punteros a nodos**: head, tail, next, prev
- **Punteros inteligentes**: unique_ptr para gestión automática de memoria
- **Punteros raw**: Para navegación en la lista enlazada
- **Gestión de memoria**: Constructor/destructor apropiados

### 6. Arquitectura en capas y principios SOLID ✅

#### Principios SOLID implementados:
- **S - Single Responsibility**: Cada clase tiene una responsabilidad específica
- **O - Open/Closed**: Extensible mediante interfaces
- **L - Liskov Substitution**: ITaskRepository puede ser sustituida por cualquier implementación
- **I - Interface Segregation**: Interfaces específicas y cohesivas
- **D - Dependency Inversion**: Dependencias inyectadas mediante interfaces

#### Capas implementadas:
1. **Repositorio (TaskRepository)**: Acceso a datos y operaciones de lista
2. **Servicio (TaskService)**: Lógica de negocio y validaciones
3. **Controlador (TaskController)**: Manejo de entrada del usuario
4. **Vista (TaskView)**: Presentación de datos

## Funcionalidades Implementadas

### a) Inserción ordenada por prioridad ✅
```cpp
// Algoritmo de inserción que mantiene orden descendente
while (current && current->priority >= priority) {
    current = current->next;
}
```

### b) Mostrar tareas pendientes ✅
```cpp
// Filtra solo tareas con estado PENDING
if (current->status == TaskStatus::PENDING) {
    pendingTasks.push_back(current);
}
```

### c) Eliminar tareas completadas ✅
```cpp
// Marca tareas como completadas y las elimina de la vista
current->status = TaskStatus::COMPLETED;
```

## Análisis de Complejidad Temporal

| Operación | Complejidad | Justificación |
|-----------|-------------|---------------|
| Insertar | O(n) | Debe encontrar posición correcta en lista ordenada |
| Eliminar | O(n) | Debe buscar el elemento en la lista |
| Mostrar pendientes | O(n) | Recorre toda la lista filtrando por estado |
| Marcar completada | O(n) | Busca el elemento por nombre |

## Medición de Tiempos
El sistema incluye medición automática de tiempos usando `std::chrono`:
- Tiempo de cada operación individual
- Tiempo total de ejecución del programa
- Precisión en microsegundos

## Clean Code Aplicado
- **Nombres descriptivos**: Variables y funciones con nombres claros
- **Funciones pequeñas**: Cada función tiene una responsabilidad específica
- **Separación de responsabilidades**: Cada capa maneja su dominio
- **Manejo de errores**: Excepciones apropiadas con mensajes descriptivos
- **Comentarios mínimos**: Código auto-documentado

## Compilación y Ejecución
```bash
# Compilar programa principal
make

# Ejecutar programa interactivo
make run

# Compilar y ejecutar demostración
g++ -std=c++17 -O2 -o demo test_demo.cpp TaskRepository.cpp TaskService.cpp TaskView.cpp
./demo

# Limpiar archivos compilados
make clean
```