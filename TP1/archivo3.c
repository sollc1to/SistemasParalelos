#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

int matriz[3][4];

int sumadorFila = 0; //Esta variable aumentara de a 4, asi accedo a la dirección correctamente.


for (int i =0; i< 3; i++){

for(int j=0; j<4;j++){

printf("Elemento  [%d][%d] de la matriz: %p. Direccion: %p\n", i,j,*(matriz+sumadorFila+j),matriz+sumadorFila+j);

}
sumadorFila = sumadorFila+4;


}


return 0;
}

