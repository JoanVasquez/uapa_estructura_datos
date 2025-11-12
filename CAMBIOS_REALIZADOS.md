# Cambios Realizados para Cumplir Criterios de Evaluación

## Criterios Implementados

### 1. Definición correcta de las estructuras de datos
- **Proyecto 1.1**: Arreglo estático de componentes `IComponente* componentes[MAX_COMPONENTES]`
- **Proyecto 1.2**: Arreglo unidimensional de estudiantes `IEstudiante* estudiantes[MAX_ESTUDIANTES]`
- **Proyecto 1.3**: Matriz bidimensional de inventario `int stock[NUM_ALMACENES][NUM_PRODUCTOS]`
- **Proyecto 1.4**: Matrices bidimensionales para stock y distancias

### 2. Implementación de funciones para manipular arreglos y matrices
- **Búsqueda lineal**: `buscarIndice()` en todos los proyectos
- **Ordenamiento burbuja**: `ordenarPorPromedio()` en proyecto 1.2
- **Filtrado con arreglos**: `filtrarAprobados()`, `filtrarNacionales()`, etc.
- **Copia de matrices**: `configurarStock()`, `configurarDistancias()`

### 3. Codificación funcional del sistema en un IDE
- Eliminación completa de `std::` prefixes
- Agregado de `using namespace std;` en todos los archivos
- Código compilable con Makefiles existentes

### 4. Uso apropiado de estructuras repetitivas
- **Bucles for tradicionales**: Para recorrer arreglos y matrices
- **Bucles while**: En algoritmos de optimización
- **Bucles anidados**: Para matrices bidimensionales

### 4.1. Condicionales anidadas aplicadas
```cpp
// Ejemplo en proyecto 1.3
for (int almacen = 0; almacen < NUM_ALMACENES; ++almacen) {
    for (int producto = 0; producto < NUM_PRODUCTOS; ++producto) {
        int stockActual = stock[almacen][producto];
        if (stockActual > 0 && stockActual < umbralMinimo && count < MAX_ALERTAS) {
            alertas[count] = {almacen, producto, stockActual, umbralMinimo};
            count++;
        }
    }
}
```

### 5. Manipulación efectiva de arreglos unidimensionales y bidimensionales

#### Arreglos Unidimensionales:
- **Proyecto 1.1**: `IComponente* componentes[MAX_COMPONENTES]`
- **Proyecto 1.2**: `IEstudiante* estudiantes[MAX_ESTUDIANTES]`
- **Proyecto 1.3**: `int productos[]` para productos agotados
- **Proyecto 1.4**: `int umbrales[NUM_PRODUCTOS]`

#### Matrices Bidimensionales:
- **Proyecto 1.3**: `int stock[NUM_ALMACENES][NUM_PRODUCTOS]` (6x15)
- **Proyecto 1.4**: 
  - `int stock[NUM_ALMACENES][NUM_PRODUCTOS]` (6x15)
  - `int distancias[NUM_ALMACENES][NUM_ALMACENES]` (6x6)

### 6. Desarrollo de funciones que trabajen directamente con arreglos y matrices estáticos

#### Funciones de Manipulación de Arreglos:
```cpp
// Búsqueda lineal en arreglo
int buscarIndice(const string& codigo) {
    for (int i = 0; i < totalElementos; i++) {
        if (arreglo[i] && arreglo[i]->getCodigo() == codigo) {
            return i;
        }
    }
    return -1;
}

// Ordenamiento burbuja
void ordenarPorPromedio() {
    for (int i = 0; i < totalEstudiantes - 1; i++) {
        for (int j = 0; j < totalEstudiantes - i - 1; j++) {
            if (estudiantes[j]->getPromedio() < estudiantes[j + 1]->getPromedio()) {
                intercambiar(j, j + 1);
            }
        }
    }
}
```

#### Funciones de Manipulación de Matrices:
```cpp
// Copia de matriz bidimensional
void configurarStock(int nuevoStock[NUM_ALMACENES][NUM_PRODUCTOS]) {
    for (int i = 0; i < NUM_ALMACENES; i++) {
        for (int j = 0; j < NUM_PRODUCTOS; j++) {
            stock[i][j] = nuevoStock[i][j];
        }
    }
}

// Recorrido de matriz con bucles anidados
void mostrarStock() const {
    for (int a = 0; a < NUM_ALMACENES; ++a) {
        for (int p = 0; p < NUM_PRODUCTOS; ++p) {
            cout << setw(6) << stock[a][p];
        }
    }
}
```

## Cambios Específicos por Proyecto

### Proyecto 1.1 - Almacén de Componentes
- Reemplazó `unordered_map` por arreglo estático
- Implementó búsqueda lineal y ordenamiento burbuja
- Funciones de filtrado que llenan arreglos resultado

### Proyecto 1.2 - Sistema Académico  
- Reemplazó `vector` por arreglo unidimensional de estudiantes
- Implementó algoritmo de ordenamiento burbuja por promedio
- Filtrado de aprobados usando estructuras repetitivas

### Proyecto 1.3 - Control de Inventario
- Ya usaba matriz bidimensional `stock[6][15]`
- Mejoró funciones para usar arreglos resultado
- Implementó bucles anidados para recorrer matriz

### Proyecto 1.4 - Reasignación Óptima
- Reemplazó `std::array` por matrices estáticas
- Implementó algoritmo greedy con bucles tradicionales
- Manipulación directa de matrices de stock y distancias

## Eliminación de Dependencias STL
- Removido: `vector`, `unordered_map`, `unique_ptr`, `function`
- Reemplazado por: Arreglos estáticos, punteros raw, funciones tradicionales
- Mantenido: Funcionalidad completa con estructuras básicas

## Comentarios Agregados
- Explicación de algoritmos de manipulación de arreglos
- Documentación de bucles anidados y condicionales
- Descripción de operaciones con matrices bidimensionales
- Comentarios sobre estructuras repetitivas utilizadas