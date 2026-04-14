#include <stdio.h>
#include <stdlib.h>

int main(){

int **x = malloc(3*sizeof(int));//Declaramos un arreglo de punteros.

int *y = malloc(3*4*sizeof(int)); //Pedimos memoria dinamica para nuestra
//matriz de 3X4. En total 12 elementos.


for (int i =0; i<3; i++){ //i<3 ya que queremos que la matriz sea de 3 filas.
*(x+i) = &y[i*4]; //X apuntara a la direccion de memoria de cada inicio de fila.

for(int j= 0; j <4;j++){

*(*(x+i)+j) =i+j;


printf("Elemento [%d][%d]: %d\n",i,j,*(*(x+i)+j));
}




}





return 0;
}

