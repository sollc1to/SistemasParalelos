#include <stdio.h>
#include <unistd.h>
#include <omp.h>



int
main (int argc, char **argv)
{

//omp_set_num_threads (10); Esta es una forma de modificar la cantidad de hilos
 


  int id;

#pragma omp parallel  private(id)

  {
    id = omp_get_thread_num ();

    if (id == 0)
       {

       printf ("Cantidad de hilos %d...\n", omp_get_num_threads ());
       } 



  }

  printf ("Cantidad de hilos %d...\n", omp_get_num_threads ());


  return 0;
}
