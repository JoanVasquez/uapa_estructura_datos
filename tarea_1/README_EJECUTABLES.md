# Ejecutables Generados

## Compilacion Exitosa ✅

Todos los proyectos han sido compilados para **Linux** y **Windows** usando cross-compilation.

### Ejecutables Linux
- `1.1_almacen/almacen` (51.8 KB)
- `1.2_bootcamp/academia` (41.9 KB) 
- `1.3_inventario/inventario` (17.7 KB)

### Ejecutables Windows
- `1.1_almacen/almacen.exe` (178.6 KB)
- `1.2_bootcamp/academia.exe` (154.1 KB)
- `1.3_inventario/inventario.exe` (128.2 KB)

## Como Compilar

### Compilacion Automatica (Ambas Plataformas)
```bash
bash compile_all.sh
```

### Compilacion Individual

#### Linux
```bash
cd [proyecto] && make clean && make
```

#### Windows
```bash
cd [proyecto] && make -f Makefile.win clean && make -f Makefile.win
```

## Caracteristicas

- **Cross-compilation**: Compilado desde Linux para Windows usando `x86_64-w64-mingw32-g++`
- **Static linking**: Ejecutables Windows incluyen librerias estaticas
- **Sin acentos**: Todos los strings compatibles con cualquier sistema
- **Arquitectura MVC**: Patron implementado en todos los proyectos
- **C++14**: Estandar moderno con `using namespace std`

## Ejecucion

### Linux
```bash
./1.1_almacen/almacen
./1.2_bootcamp/academia
./1.3_inventario/inventario
```

### Windows
```cmd
1.1_almacen\almacen.exe
1.2_bootcamp\academia.exe
1.3_inventario\inventario.exe
```

Los ejecutables Windows son completamente portables y no requieren instalacion adicional.