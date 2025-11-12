#!/bin/bash
echo "Compilando todos los proyectos para Linux..."

cd 1.1_almacen
echo "=== Compilando Almacen ==="
make clean && make
cd ..

cd 1.2_bootcamp
echo "=== Compilando Academia ==="
make clean && make
cd ..

cd 1.3_inventario
echo "=== Compilando Inventario ==="
make clean && make
cd ..

echo "Compilacion completada!"