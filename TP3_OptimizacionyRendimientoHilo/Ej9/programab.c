#include <stdio.h>
#include <emmintrin.h>



int main(int argc, char * argv[]){


long T = atol(argv[1]);
long aux = T - (T%4); // SI T=13. 13 - (13%4) = 13 -  1 = 12.

printf("El tamaño definido es %ld\n",T);

int i, resultado[4], sumafinal = 0;
__m128i  carga, suma; //Declaramos dos estructuras SIMD. Registros de 128bits.

suma =  _mm_set_epi32(0,0,0,0); //Llenamos el arreglo suma con ceros.


int *a;
if (posix_memalign((void**)&a, 16, T * sizeof(int)) != 0) {
    printf("Error al reservar memoria alineada\n");
    return 1;
}




for( i = 0; i < T; i++){

a[i] = i;
//Cargamos nuestro arreglo.

}



for(i = 0; i < aux; i+=4){

carga = _mm_load_si128((__m128i*)&a[i]); //Load carga con alineacion en memoria. Cargamos 4 enteros
//Le pasamos la direccion de memoria en donde puede "rescatar" 128 bits.

suma = _mm_add_epi32(carga,suma); //Sumamos enteros de 32 bits de los registros carga y suma y guardamos el resultado en suma.


}


for (aux; aux < T; aux++){

sumafinal = sumafinal + a[aux]; //Le sumamos las posiciones que no podemos procesar con funciones vectoriales.

}




_mm_store_si128((__m128i*)&resultado,suma);//Guardamos las 4 sumas restantes en el vector resultado.



sumafinal = sumafinal + resultado[0] + resultado[1] + resultado[2] + resultado[3];



printf("Suma final %d\n",sumafinal);


free(a);

}
