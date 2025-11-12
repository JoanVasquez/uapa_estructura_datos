#!/bin/bash
echo "Compilando todos los proyectos..."

for dir in 1.1_almacen 1.2_bootcamp 1.3_inventario; do
    echo "=== Compilando $dir ==="
    cd $dir
    
    echo "  -> Linux"
    make clean && make
    
    echo "  -> Windows"
    make -f Makefile.win clean && make -f Makefile.win
    
    cd ..
done

echo "Compilacion completada!"
echo "Ejecutables Linux: almacen, academia, inventario"
echo "Ejecutables Windows: almacen.exe, academia.exe, inventario.exe"