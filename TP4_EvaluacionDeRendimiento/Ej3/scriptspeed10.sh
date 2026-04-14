
#!/bin/bash
#SBATCH --partition=Blade
#SBATCH -N 1
#SBATCH --exclusive
#SBATCH -o salida10.txt
#SBATCH -e errores10.txt

echo "Programa 1"

./p10

echo"Programa 2"

./p10op
