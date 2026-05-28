#include <stdio.h>

int main(){

int i, x[1000], y[1001],z[1000];

//Hay una dependencia del tipo O1 \intersect O2 \= vacio. Es decir dos procesos intentarian leer el mismo dato al
//mismo tiempo. 
int N = 1000;
int a = N-2;
#pragma omp for shared(a) 
for(i = a; i >=0; i--){
x[i] = x[i] + y[i+1];

}


//Al separarlo en dos for, y no poner la clausula nowait, el segundo for se ejecutara luego
//de que terminen todos los procesos en el primer for. X lo que no habrá problemas de accesos.

#pragma omp for shared(a)
for (i=a; i >=0;i--){
y[i] = y[i] + z[i];

}





return 0;

}

 
