# Guia de Compilacion

## Para Linux/macOS

### Compilacion Individual
```bash
# Almacen de componentes
cd 1.1_almacen && make clean && make

# Sistema academico  
cd 1.2_bootcamp && make clean && make

# Inventario multi-sucursal
cd 1.3_inventario && make clean && make
```

### Compilacion Automatica
```bash
# Ejecutar script
bash compile_all.sh
```

## Para Windows

### Compilacion Individual
```cmd
# Almacen de componentes
cd 1.1_almacen
mingw32-make -f Makefile.win clean
mingw32-make -f Makefile.win

# Sistema academico
cd 1.2_bootcamp
mingw32-make -f Makefile.win clean
mingw32-make -f Makefile.win

# Inventario multi-sucursal
cd 1.3_inventario
mingw32-make -f Makefile.win clean
mingw32-make -f Makefile.win
```

### Compilacion Automatica
```cmd
# Ejecutar script
compile_all.bat
```

## Ejecutables Generados

### Linux/macOS
- `1.1_almacen/almacen`
- `1.2_bootcamp/academia`
- `1.3_inventario/inventario`

### Windows
- `1.1_almacen/almacen.exe`
- `1.2_bootcamp/academia.exe`
- `1.3_inventario/inventario.exe`

## Requisitos

### Linux/macOS
- g++ con soporte C++14
- make

### Windows
- MinGW-w64 o similar
- mingw32-make

## Notas
- Todos los acentos han sido removidos para compatibilidad
- Makefiles separados para cada plataforma
- Scripts de compilacion automatica incluidos