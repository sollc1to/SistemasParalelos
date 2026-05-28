#include <stdio.h>
#include <omp.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>

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

  long num_steps = 800000000;
  double step = 1.0 / (double) num_steps;

  double pi = 0;
  double suma,x;


 int hilosDisponibles = 0;



#pragma omp parallel num_threads(12) reduction(+:suma) shared(num_steps)
{

#pragma omp for private(x)

for (int i = 0; i < num_steps; i++){
      x = (i + 0.5) * step;
      suma = suma + 4.0 / (1.0 + x * x);
   }


 }

  pi = suma * step;

  printf ("%f\n", pi);



  t = sampleTime () - t;
  printf ("Tiempo transcurrido: %f segundos\n", t);

return 0;
}
