@echo off
echo Compilando todos los proyectos para Windows...

cd 1.1_almacen
echo === Compilando Almacen ===
mingw32-make -f Makefile.win clean
mingw32-make -f Makefile.win
cd ..

cd 1.2_bootcamp
echo === Compilando Academia ===
mingw32-make -f Makefile.win clean
mingw32-make -f Makefile.win
cd ..

cd 1.3_inventario
echo === Compilando Inventario ===
mingw32-make -f Makefile.win clean
mingw32-make -f Makefile.win
cd ..

echo Compilacion completada!
pause