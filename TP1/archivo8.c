#include <stdio.h>
#include <stdlib.h>

int main(){

int *x[3]; //Declaramos un arreglo de punteros.

int *y = malloc(3*4*sizeof(int)); //Pedimos memoria dinamica para nuestra
//matriz de 3X4.


for (int i =0; i<3; i++){ //i<3 ya que queremos que la matriz sea de 3 filas.
*(x+i) = &y[i*4]; //X apuntara a la direccion de memoria de cada inicio de fila.

for(int j= 0; j <4;j++){

*(*(x+i)+j) =i+j;

}




}





return 0;
}

