#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

float arreglo[5];

*(arreglo+5) = 1234;
*(arreglo+4) = 234534535.2;

printf("El quinto elemento es %f:",arreglo[10]);
printf("EL quinto elemento es %f:",arreglo[4]);


return 0;

}




