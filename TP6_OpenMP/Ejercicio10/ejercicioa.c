
// EJERCICIO 10.a

#include <omp.h>

int main() {

int i, j, A[1000];

j =5;

#pragma omp parallel num_threads(12)
{
#pragma omp for firstprivate(j)

for (i = 0; i < 1000; i++) {
j+=2;
A[i] =  3*j*j*j + 2*j*j + 10*j +2;
}
}




/*
Mientras un hilo calcula j, otro hilo quiere utilizar el valor de j.
La forma de solucionarlo seria definir a la variable j como privada de cada proceso.
I1 \intersect O2 \= vacio

*/


    

    return 0;
}
