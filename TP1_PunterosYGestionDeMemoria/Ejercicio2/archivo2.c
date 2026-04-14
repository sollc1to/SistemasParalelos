#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

float arreglo[5];

*(arreglo+4) = 234534535.2; //Como va de 0..4, la quinta posicion seria a[4]

printf("EL quinto elemento es %f:",arreglo[4]);


return 0;

}




