#include <stdlib.h>
#include  <stdio.h>


int main(int argc, char * argv[]){

long T = atol(argv[1]);

printf("El tamaño definido es %ld\n",T);


int i;
long a = 0; //Declaro long por si se desborda.
int *m = malloc(T*(sizeof(int))); 

for (int i = 0; i < T; i++){

m[i] = i;

}

for (i=0; i < T; i++){
a =a+ m[i];

}

printf("El resultado es %ld",a);

free(m);

return 0;
}

