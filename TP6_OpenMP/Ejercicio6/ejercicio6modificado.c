#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include <omp.h>

void
trabajo (int id)
{
  printf ("%d: Trabajo muy duro...\n", id);
  sleep (1);
  printf ("%d: como un esclavo!\n", id);
  sleep (1);
}


double
sampleTime ()
{
  struct timespec tv;

  clock_gettime (CLOCK_MONOTONIC_RAW, &tv);

  return ((double) tv.tv_sec + ((double) tv.tv_nsec) / 1000000000.0);
}

int
main ()
{
  double t;

  t = sampleTime ();
int N = 8;



#pragma omp parallel for schedule(static,2)


for (int i =0 ; i <N; i=i+1){

 trabajo(i);


}



  t = sampleTime () - t;
  printf ("Tiempo de ejecucion: %f\n ", t);


  return 0;
}
