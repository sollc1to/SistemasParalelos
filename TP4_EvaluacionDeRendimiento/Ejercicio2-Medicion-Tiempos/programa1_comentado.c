#include <stdio.h>
#include <time.h>
#include <unistd.h>

double sampleTime() {
   /* struct: agrupa variables relacionadas bajo un mismo nombre.
    * timespec tiene dos campos: tv_sec (segundos enteros) y
    * tv_nsec (nanosegundos). Juntos representan un instante de tiempo.
    */

   struct timespec tv;

   /* Consulta el reloj de hardware y llena tv con el tiempo actual.
    * CLOCK_MONOTONIC_RAW: reloj puro, no lo afectan ajustes del SO.
    */
   clock_gettime(CLOCK_MONOTONIC_RAW, &tv);

   /* Convierte los dos campos a un único double en segundos:
    * segundos enteros + nanosegundos/10^9
    */
   return ((double)tv.tv_sec + (double)tv.tv_nsec / 1000000000.0);
}

int main(){
   double t;

   t = sampleTime();      /* captura tiempo ANTES de la tarea */
   sleep(1);              /* tarea a medir                    */
   t = sampleTime() - t; /* tiempo DESPUÉS menos tiempo ANTES = duración */

   printf("tiempo transcurrido: %f segundos\n", t);
   return 0;
}
