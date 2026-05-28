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
  double suma[12];		//12 pq mí compu tiene 12 nucleos máximos.



  for (int i = 0; i < 12; i++)
    {
      suma[i] = 0;

    }

  int hilosDisponibles = 0;

#pragma omp parallel num_threads(12) shared(num_steps) shared(step) shared(suma) shared(hilosDisponibles)

  {
    hilosDisponibles = omp_get_num_threads ();
    double x;
    int id = omp_get_thread_num ();	//Obtenemos id del hilo
    int ini, final;
    int paso = num_steps / hilosDisponibles;	//suponemos resto 0



    ini = id * paso;
    final = (id + 1) * paso;
   // printf ("%d: voy desde %d hasta %d\n", id, ini, final);


   // printf ("id: %d valor de suma[id] antes de sumar: %f\n", id, suma[id]);


    for (int i = ini; i < final; i++)
      {
	x = (i + 0.5) * step;


	suma[id] = suma[id] + 4.0 / (1.0 + x * x);

      }
   // printf ("%d: che mira, obtuve %f\n", id, suma[id]);

  }



  for (int i = 0; i < hilosDisponibles; i++)
    {

      pi += suma[i];

    }

  pi = pi * step;

  printf ("%f\n", pi);



  t = sampleTime () - t;
  printf ("Tiempo transcurrido: %f segundos\n", t);

return 0;
}
