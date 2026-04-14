#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main(){

/*int matriz[3][4]; */


//Voy a declarar una matriz de punteros.


int** f = malloc(3*sizeof(int*)); //Filas la cual cada posicion guardara la posicion del puntero de las columnas.

int* c = malloc(12*sizeof(int)); //Cantidad de elementos de las columnas


f[0] = c; //La primera fila apunta a la direccion de memoria de la primer columna de c.

f[1] =c+4; //La segunda fila a punta a la direccion de memoria de la segunda columna en c. Como c es de tipo *int,
           //Si hacemos c+1 avanza 1 entero. Hacemos c+4 porque la columna tiene 4 enteros.

f[2]= c+8;

printf("Direcciones de memoria de las columnas: %p,%p,%p", f[0],f[1],f[2]);

for(int i =0; i <3;i++){

for(int j=0;j<4;j++){

*(*(f+i)+j) = 2+i; //Primero buscamos el valor que hay en la fila, luego el de las columnas. Los parentesis son importantes!!! Si se cambian hay error 

}

}




for (int i =0; i< 3; i++){

for(int j=0; j<4;j++){

printf("Elemento  [%d][%d] de la matriz: %d. Direccion: %p\n", i,j,*(*(f+i)+j),&(*(*(f+i)+j)));

}

}


return 0;
}

