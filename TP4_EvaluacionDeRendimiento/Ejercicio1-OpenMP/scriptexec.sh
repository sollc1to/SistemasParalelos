#!/bin/bash
#SBATCH --partition=Blade
#SBATCH -N 1
#SBATCH --exclusive




#La altura y el ancho se ingresan por parametros.

listaNucleos="1 $(seq 2 2 8)" #Va desde 2 hasta 8 con paso 2.

for cores in $listaNucleos; do

echo Experimento con cores: $cores

export OMP_NUM_THREADS=$cores #Ejecutamos con cores cantidad de nucleos.

./julia $1$ $2$

echo ------------- 

done


