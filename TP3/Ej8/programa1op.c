#include <stdlib.h>

#define Y 10000
#define X 50000

int
main ()
{
  int i, j;
  int **m;

  m = malloc (X * sizeof (int *));

  for (i = 0; i < X; i++)
    {
      m[i] = malloc (Y * sizeof (int));

      for (j = 0; j < Y; j++)
	{
	  m[i][j] = i + j;	//Para mejorar la localidad espacial, cambiamos los indices de acceso.
	  //Para mejorar la localidad temporal, a medida que vamos creando la matriz vamos asignadole los valores.
	}
    }

  free (m);

  return 0;
}
