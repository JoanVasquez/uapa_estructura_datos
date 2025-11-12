# Compilacion Cruzada Linux/Windows

## ✅ Compilacion Completada

### Archivos Generados

**Linux (ejecutables nativos):**
- `1.1_tareas_priorizadas/tareas_priorizadas`
- `1.2_stock_minimo_de_productos/stock_minimo`
- `1.3_historial_web_con_lista_doble/historial_web`

**Windows (ejecutables .exe):**
- `1.1_tareas_priorizadas/tareas_priorizadas.exe`
- `1.2_stock_minimo_de_productos/stock_minimo.exe`
- `1.3_historial_web_con_lista_doble/historial_web.exe`

### Comandos de Compilacion

#### Compilar Todo
```bash
./build_all.sh
```

#### Compilar Individual
```bash
cd 1.1_tareas_priorizadas
make all          # Compila Linux y Windows
make linux        # Solo Linux
make windows      # Solo Windows
make clean        # Limpia archivos
```

#### Ejecutar Programas
```bash
# Linux
make run-linux
make demo-linux

# Windows (requiere wine)
make run-windows
make demo-windows
```

### Configuracion Makefile

```makefile
CXX_LINUX = g++
CXX_WINDOWS = x86_64-w64-mingw32-g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude -static-libgcc -static-libstdc++

all: linux windows

linux: programa demo
windows: programa.exe demo.exe
```

### Caracteristicas

- **Compilacion cruzada**: Genera ejecutables Windows desde Linux
- **Bibliotecas estaticas**: `-static-libgcc -static-libstdc++`
- **Sin dependencias**: Ejecutables independientes
- **Mismo codigo fuente**: Sin cambios entre plataformas
- **Sin acentos**: Compatible con ambos sistemas

### Verificacion

Todos los programas compilan sin errores y warnings:
- ✅ Tareas priorizadas (Linux + Windows)
- ✅ Stock minimo (Linux + Windows)  
- ✅ Historial web (Linux + Windows)

Los ejecutables .exe pueden transferirse a Windows y ejecutarse directamente sin instalaciones adicionales.