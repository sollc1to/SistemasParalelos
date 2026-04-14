#include <stdio.h>


int main(){
int matriz[3][4];

for(int i =0; i < 3; i++){

for(int j =0; i < 4;i++){

matriz[i][j] = i+j;

}

}




for(int i=0; i <3; i++){

for(int j =0; j<4; j++){

printf("Elemento en posicion[%d][%d]: %d. Direccion: %p\n",i,j,matriz[i][j], &matriz[i][j]);

}


}

return 0;

}
