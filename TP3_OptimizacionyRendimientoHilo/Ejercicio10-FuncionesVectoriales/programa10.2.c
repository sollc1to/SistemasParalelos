#include <stdlib.h>
#include <stdio.h>
#include <emmintrin.h>
int main() {
    int i, elementos = 100000000;
    int *v, aux1;
__m128i carga,suma,resta, result, comparar;
__m128i andresta, andsuma;
v = malloc(elementos * sizeof(int)); //Arreglo de 400 millones de bytes 


for(i=0; i < elementos;i++)
v[i] = i;


suma = _mm_set_epi32(5,5,5,5);//Puedo hacer tambien _mm_set_epi1.. Carga el entero 4 veces.

resta = _mm_set_epi32(-5,-5,-5,-5);

comparar = _mm_set_epi32(50000000,50000000,50000000,50000000); //Esto es para poder comparar los 4 elementos

for(i=0; i <elementos;i+=4){

carga = _mm_load_si128((__m128i*)&v[i]); //Cargamos 4 enteros del arreglo.


result = _mm_cmpgt_epi32(carga, comparar); //carga > comparar? 

//Si algun elemento da true, tendremos como mascara 0xFFFFFFFF. Si da false, tendremos como mascara 0.

//Entonces, si da true, significa que tenemos que restar 5. Como hacemos esto?
//Primero hacemos un AND entre resta y result.

andresta = _mm_and_si128(result, resta); 	

//result = _mm_cmplt_epi32(carga,comparar); carga < comparar? En vez de hacer esto uso el andnot

andsuma = _mm_andnot_si128(result, suma);

result = _mm_or_si128(andsuma, andresta);


//Realizamos una suma entre result y carga.


carga =_mm_add_epi32(result,carga);


//Devolemos ese resultado al arreglo.


_mm_store_si128((__m128i*)&v[i],carga);


}


/*  for (i = 0; i < elementos; i++)
        if (v[i] > 50000000)
            v[i] = v[i] - 5;
        else
            v[i] = v[i] + 5;
*/



    printf("elemento 0: %d\n", v[0]);
    printf("elemento 49999999: %d\n", v[49999999]);
    printf("elemento 50000000: %d\n", v[50000000]);
    printf("elemento 99999999: %d\n", v[99999999]);

    return 0;
}
