#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int
main (int argc, char **argv)
{
  int n = 0;

#pragma omp parallel num_threads (10)
  {
#pragma omp critical
    {
      if (!n)
	{

	  printf ("Cantidad de hilos en esta seccion %d...\n",
		  omp_get_num_threads ());
	  n++;
	}

    }

  }

  return 0;

}
