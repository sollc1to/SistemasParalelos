#include <stdlib.h>
#define X 1000000

int
main ()
{
  int i, j, **m;

  m = malloc (900 * sizeof (int *));	// Reserva 900* 8 bytes.

  for (i = 0; i < 900; i++)
    m[i] = malloc (X * sizeof (int));
  //A cada elemento de la fila, le asigna 1000000* 4 Bytes. Es decir 4 millones de bytes. Cada columna tiene
  //Tamaño de 4 millones de bytes.



  for (i = 0; i < 300; i++)
    {				//Desde i= 0..299 m[i][j] = 0. 
      for (j = 0; j < X; j++)
	{

	  m[i][j] = 0;
	  //Desde i = 300.. 599 m[i][j] = 1
	}			//Desde i= 600..900 m[i][j] = 2
    }



  for (i = 300; i < 600; i++)
    {
      for (j = 0; j < X; j++)
	{
	  m[i][j] = 1;
	}
    }

  for (i = 600; i < 900; i++)
    {

      for (j = 0; j < X; j++)
	{

	  m[i][j] = 2;

	}

    }


  return 0;
}
