#include <stdio.h>

#include <time.h>
#include <unistd.h>

double sampleTime() {
   struct timespec tv;
   clock_gettime(CLOCK_MONOTONIC_RAW, &tv);
   return ((double)tv.tv_sec+((double)tv.tv_nsec)/1000000000.0);
}

void main(){
   double t;
   t = sampleTime();
     
  long num_steps = 800000000;
  double step;
  int i;
  double x, pi, sum = 0.0;

  step = 1.0 / (double) num_steps;

  for (i = 0; i < num_steps; i++)
    {
      x = (i + 0.5) * step;
      sum = sum + 4.0 / (1.0 + x * x);
    }
  pi = step * sum;
  printf ("%f/n", pi);


   t = sampleTime() - t;
   printf("tiempo transcurrido: %f segundos\n", t);


}
