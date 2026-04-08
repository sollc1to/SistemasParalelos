

#include <stdio.h>
#include <emmintrin.h>



int main(int argc, char * argv[]){
long T = atol(argv[1]);
if (T-1%4==0){
T--;
} //Para evitar que agarre basura el procesamiento vectorial.

printf("El tamaño definido es %ld\n",T);

int i, resultado[4], sumafinal = 0;
__m128i  carga, suma; //Declaramos dos estructuras SIMD. Registros de 128bits.

suma =  _mm_set_epi32(0,0,0,0); //Llenamos el arreglo suma con ceros.

int *a = malloc(T*sizeof(int)); //Declaramos un arreglo dinamico.




for( i = 0; i < T; i++){

a[i] = i;
//Cargamos nuestro arreglo.

}



for(i = 0; i < T; i+=4){

carga = _mm_load_si128((__m128i*)&a[i]); //Load carga con alineacion en memoria. Cargamos 4 enteros
//Le pasamos la direccion de memoria en donde puede "rescatar" 128 bits.

suma = _mm_add_epi32(carga,suma); //Sumamos enteros de 32 bits de los registros carga y suma y guardamos el resultado en suma.


}


if(!(T%4==0)){//Si no es multiplo de 4.
i = T-1;

while(i%4 != 0){ //Recorremos de atras hacia adelante hasa una pos multiplo de 4.


sumafinal = sumafinal + a[i];

i--;
}


}


//Al final de la suma, el registro suma tendra [a,b,c,d] y tenemos que sumar esos resultados.


_mm_store_si128((__m128i*)&resultado,suma);//Guardamos las 4 sumas restantes en el vector resultado.



sumafinal = resultado[0] + resultado[1] + resultado[2] + resultado[3];



printf("Suma final %d\n",sumafinal);


free(a);

}
