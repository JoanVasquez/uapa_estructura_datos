# Sistema de Tareas Priorizadas

## Descripción
Aplicación de gestión de tareas con lista doblemente enlazada que mantiene las tareas ordenadas por prioridad en orden descendente.

## Arquitectura
- **Repositorio**: Manejo de datos con lista doblemente enlazada
- **Servicio**: Lógica de negocio y validaciones
- **Controlador**: Manejo de entrada del usuario
- **Vista**: Presentación de datos
- **Principios SOLID**: Inversión de dependencias, responsabilidad única

## Funcionalidades
1. Insertar tareas ordenadas por prioridad (descendente)
2. Mostrar tareas pendientes
3. Marcar tareas como completadas
4. Eliminar tareas completadas
5. Medición de tiempos de ejecución

## Compilación y Ejecución
```bash
make
make run
```

## Estructuras de Datos
- Lista doblemente enlazada para inserción/eliminación eficiente
- Ordenamiento automático por prioridad
- Punteros next/prev para navegación bidireccional

## Complejidad Temporal
- Inserción: O(n) - busca posición correcta
- Eliminación: O(n) - busca elemento
- Mostrar pendientes: O(n) - recorre lista
- Marcar completada: O(n) - busca elemento