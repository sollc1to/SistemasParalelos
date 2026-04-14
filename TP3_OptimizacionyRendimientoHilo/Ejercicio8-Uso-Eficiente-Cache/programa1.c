#include <stdlib.h>

#define Y 10000
#define X 50000

int main() {
    int i, j;
    int **m;

    m = malloc(X * sizeof(int*)); //Pedimos memoria para almacenar 50000 direcciones de punteros.

    for (i = 0; i < X; i++)
        m[i] = malloc(Y * sizeof(int)); //En cada direccion de memoria de m almacenaremos 10000*4 bytes. 
					//Es decir, tenemos una matriz con punteros.

    for (j = 0; j < Y; j++)	
        for (i = 0; i < X; i++) //En esta matriz recorremos m[0][1], m[1][1], m[2][1].. Es decir, recorremos por COLUMNAS en vez de filas.
				//Eso es muy ineficiente, rompiendo con la localidad espacial.
            m[i][j] = i + j;

    return 0;
}
