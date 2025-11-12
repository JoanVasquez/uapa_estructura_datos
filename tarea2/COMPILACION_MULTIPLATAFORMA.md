# Compilacion Multiplataforma

## Cambios Realizados

### Acentos Removidos
- Todos los strings con acentos han sido corregidos
- "crítico" → "critico"
- "opción" → "opcion"
- "página" → "pagina"
- "ejecución" → "ejecucion"
- "navegación" → "navegacion"
- "válida" → "valida"
- "inválida" → "invalida"

### Soporte Windows/Linux

#### Makefiles Actualizados
Todos los Makefiles ahora detectan automaticamente el sistema operativo:

```makefile
# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    CXX = g++
    TARGET = programa.exe
    DEMO_TARGET = demo.exe
    RM = del /Q
    RUN_CMD = .\\$(TARGET)
else
    CXX = g++
    TARGET = programa
    DEMO_TARGET = demo
    RM = rm -f
    RUN_CMD = ./$(TARGET)
endif
```

#### Compilacion en Linux
```bash
make          # Compila programa
make run      # Ejecuta programa
make demo     # Compila y ejecuta demo
make clean    # Limpia archivos
```

#### Compilacion en Windows
```cmd
make          # Compila programa.exe
make run      # Ejecuta programa.exe
make demo     # Compila y ejecuta demo.exe
make clean    # Limpia archivos .exe
```

## Proyectos Actualizados

### 1.1_tareas_priorizadas
- ✅ Acentos removidos
- ✅ Makefile multiplataforma
- ✅ Genera tareas_priorizadas.exe en Windows

### 1.2_stock_minimo_de_productos
- ✅ Acentos removidos
- ✅ Makefile multiplataforma
- ✅ Genera stock_minimo.exe en Windows

### 1.3_historial_web_con_lista_doble
- ✅ Acentos removidos
- ✅ Makefile multiplataforma
- ✅ Genera historial_web.exe en Windows

## Verificacion

### Linux
```bash
cd 1.1_tareas_priorizadas && make demo
cd ../1.2_stock_minimo_de_productos && make demo
cd ../1.3_historial_web_con_lista_doble && make demo
```

### Windows
```cmd
cd 1.1_tareas_priorizadas && make demo
cd ..\1.2_stock_minimo_de_productos && make demo
cd ..\1.3_historial_web_con_lista_doble && make demo
```

Todos los programas ahora compilan y ejecutan correctamente en ambos sistemas operativos sin acentos en la salida.