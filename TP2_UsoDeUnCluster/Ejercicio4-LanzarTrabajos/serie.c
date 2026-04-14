#define _GNU_SOURCE 
// Habilita extensiones específicas de GNU (glibc).
// Es necesario para poder usar funciones no estándar como sched_getcpu().

#include <stdio.h>
// Permite usar funciones de entrada/salida como printf()

#include <unistd.h>
// Contiene funciones del sistema POSIX como gethostname()

#include <sched.h>
// Define funciones relacionadas con planificación de CPU,
// incluyendo sched_getcpu()

int main(int argc, char *argv[]) {
// Punto de entrada del programa.
// argc = cantidad de argumentos
// argv = vector de argumentos (no se usan en este caso)

   char hostname[128];
   // Declara un arreglo de caracteres (string) de tamaño 128
   // donde se va a guardar el nombre del host (máquina/nodo)

   gethostname(hostname, sizeof(hostname));
   // Llama al sistema para obtener el nombre del host actual
   // y lo guarda en "hostname"
   // sizeof(hostname) indica el tamaño máximo del buffer

   printf("Ejecutando en nodo %s, core %d\n", hostname, sched_getcpu());
   // Imprime:
   // - %s → el nombre del nodo (hostname)
   // - %d → el número de CPU/core donde se está ejecutando el proceso
   // sched_getcpu() devuelve el ID del core actual

   return 0;
   // Finaliza el programa indicando ejecución exitosa
}

