#!/bin/bash

echo "=== COMPILANDO TODOS LOS PROYECTOS PARA LINUX Y WINDOWS ==="

# Compilar tareas priorizadas
echo "Compilando 1.1_tareas_priorizadas..."
cd 1.1_tareas_priorizadas
make clean
make all
echo "✓ Tareas priorizadas compilado"
cd ..

# Compilar stock minimo
echo "Compilando 1.2_stock_minimo_de_productos..."
cd 1.2_stock_minimo_de_productos
make clean
make all
echo "✓ Stock minimo compilado"
cd ..

# Compilar historial web
echo "Compilando 1.3_historial_web_con_lista_doble..."
cd 1.3_historial_web_con_lista_doble
make clean
make all
echo "✓ Historial web compilado"
cd ..

echo ""
echo "=== COMPILACION COMPLETADA ==="
echo "Archivos generados:"
echo "Linux:"
echo "  - 1.1_tareas_priorizadas/tareas_priorizadas"
echo "  - 1.2_stock_minimo_de_productos/stock_minimo"
echo "  - 1.3_historial_web_con_lista_doble/historial_web"
echo ""
echo "Windows:"
echo "  - 1.1_tareas_priorizadas/tareas_priorizadas.exe"
echo "  - 1.2_stock_minimo_de_productos/stock_minimo.exe"
echo "  - 1.3_historial_web_con_lista_doble/historial_web.exe"
echo ""
echo "Para ejecutar demos:"
echo "  make demo-linux   # Ejecuta demo en Linux"
echo "  make demo-windows # Ejecuta demo en Windows (requiere wine)"