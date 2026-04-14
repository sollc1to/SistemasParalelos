#!/bin/bash
#SBATCH --partition=Blade 
#SBATCH -N 1
#SBATCH --exclusive
#SBATCH -o salida8.txt
#SBATCH -e error8.txt


echo Programa 1
time ./p1

echo Programa 2
time ./p1o
