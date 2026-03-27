#!/bin/bash
#SBATCH -N 1
#SBATCH --exclusive
#SBATCH --nodelist=nodo6
#SBATCH --partition=Blade
#SBATCH -o salida.txt
#SBATCH -e errores.txt

echo Iniciando el programa
./serie
echo Fin del programa

