#include <stdio.h>

int main(){

int *p; //Declaramos un puntero entero
p = (int *) malloc(sizeof(int)); //Pedimos memoria dinamica. El tamaño 
//es el tamaño de un int. Osea 32 bits. 

*p = 50; //Le asignamos a la posicion inicial de la memoria el numero 50
 
