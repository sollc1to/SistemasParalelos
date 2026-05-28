#!/bin/bash
export OMP_NUM_THREADS=2
echo "Ejecucion del programa con dos hilos"
./ej6o

export OMP_NUM_THREADS=4

echo "Ejecucion del programa con cuatro hilos"
./ej6o

export OMP_NUM_THREADS=6
echo "Ejecucion del programa con 6 hilos"
./ej6o

export OMP_NUM_THREADS=8

echo "Ejecucion del programa con 8 hilos"

./ej6o
