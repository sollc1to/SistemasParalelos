#!/bin/bash

NOMBRE=$1 # El parametro 1 es el nombre.

cat <<EOF > $NOMBRE  # Hacemos un archivo con el nombre NOMBRE, incluyendo todo el contenido hasta EOF.
#!/bin/bash
#SBATCH --partition=Blade --nodelist=nodo3
#SBATCH -e forzne.txt
#SBATCH -o forzno.txt

# Tu código acá

EOF

chmod +x $NOMBRE  # Le damos permisos de ejecucion.

echo "Script $NOMBRE creado"


