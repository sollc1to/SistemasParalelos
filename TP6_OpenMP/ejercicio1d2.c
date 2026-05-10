#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int
main (int argc, char **argv)
{
  int id;

#pragma omp parallel num_threads (10) private(id)

  {
    id = omp_get_thread_num ();

    if (id == 0)
      {

	printf ("Cantidad de hilos %d...\n", omp_get_num_threads ());
      }


   
  }

printf("Cantidad de hilos %d...\n", omp_get_num_threads());


return 0;
}
