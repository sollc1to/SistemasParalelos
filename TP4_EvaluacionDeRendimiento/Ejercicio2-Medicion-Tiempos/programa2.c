#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define X 1000


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





void leerDatos() {
   //aquí va un código que carga datos a las matrices a y b
   sleep(1); //simula la lectura de datos
}

void imprimirDatos() {
   //aquí va un código que imprime datos de la matriz c
   sleep(1); //simula la escritura de datos
}

int main(int argc, char *argv[])
{
   int w, n, i, j, k, r, **a, **b, **c, **aux;
double t;

t = sampleTime();


   if (argc != 2){
      printf("Argumento requerido: iteraciones\n");
      exit(1);
   }

   n = atoi(argv[1]);

   // Reserva de memoria
   a = malloc(X * X * sizeof(int*));
   b = malloc(X * X * sizeof(int*));
   c = malloc(X * X * sizeof(int*));
   for (i = 0; i < X; i++) {
      a[i] = malloc(X * sizeof(int));
      b[i] = malloc(X * sizeof(int));
      c[i] = malloc(X * sizeof(int));
   }

   // Inicialización de matrices
   leerDatos();

   // Kernel de la aplicación
   for (w = 0; w < n; w++) {
      // A continuación se multiplican dos matrices de 1000x1000
      for(i = 0; i < X; ++i)
         for(k = 0; k < X; ++k) {
            r = a[i][k];
            for(j = 0; j < X; ++j)
               c[i][j] += r * b[k][j];
         }
      aux = a;
      a = c;
      c = aux;
   }

   // Finalización
   imprimirDatos();
  t = sampleTime() - t;

printf("Tiempo transcurrido %f segundos",t);
 
return 0;
}
