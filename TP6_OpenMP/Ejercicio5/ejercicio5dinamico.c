#include <stdio.h>
#include <omp.h>
 int main ()
{
  long num_steps = 800000000;
  double step;
  int paso;
  double pi;
  double suma [12];

int hilosDisponibles =0;
  step = 1.0 / (double) num_steps;

#pragma omp parallel shared(num_steps) shared(step) shared(suma) shared(hilosDisponibles)
{
hilosDisponibles = omp_get_num_threads ();
double x;
  int id = omp_get_thread_num ();	//Obtenemos id del hilo
  int ini, final;
  paso = num_steps / hilosDisponibles;	//suponemos resto 0


suma[id] = 0;

  ini 	= id * paso;
  final = (id == hilosDisponibles-1) ? num_steps : (id + 1) * paso;
	printf("%d: voy desde %d hasta %d\n",id,ini,final);

  for (int i = ini; i < final; i++)
    {
      x = (i + 0.5) * step;

      suma[id] = suma[id] + 4.0 / (1.0 + x * x);
    }
	printf("%d: che mira, obtuve %f\n",id,suma[id]);

}



for (int i =0; i < hilosDisponibles;i++){ 

pi+= suma[i];

}



printf ("%f\n", pi);


return 0;
}
