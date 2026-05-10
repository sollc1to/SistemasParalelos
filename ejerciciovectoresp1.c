#include <emmintrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <smmintrin.h>          //Para la multiplicacion


include <stdlib.h>
#include <stdio.h>

int main() {
   int i, elementos = 100000000;
   int *v;
   v = malloc(elementos * sizeof(int));
__m128i carga, comparar1, comparar2, resta, registro2, result, resul1 , suma, multipli, registro5;

registro2= _mm_set1_epi32(2); //Cargamos 2 en el registro.
registro5 = _mm_set1_epi32(5); //Carhamos 5 en el registro.

comparar1= _mm_set1_epi32(50000000); //Cargamos 50 millones en comparar1.

comparar2 = _mm_set1_epi32(10000000); //Para realizar la segunca comparacion

   //no vectorizar este for
   for (i = 0; i < elementos; i++)
      v[i] = i;





for( i =0; i < elementos;i++){

carga = _mm_load_si128((__m128i*)&[v]); //Cargamos las 4 posiciones.

//Primero debemos comparar si es mayor a 50.000.000

result = _mm_cmpgt_epi32(carga,comparar1); //Es carga mayor a 50 milloones?

resta = _mm_and_si128(result,carga); //Mascara de los que si son mayores.
//Restarle 5 a resta.

resta = _mm_sub_epi32(resta,registro5); //Restamos 5


result = _mm_andnot_si128(result,carga); //Mascara negada y la carga. A estos tenemos que seguir evaluando.


result1 = _mm_cmpgt_(result,comparar2); //Es carga mayor a 10 millones? 

//S es mayor debemos multiplicarlo x dos. Si no, sumarlo 5.

multipli = _mm_and_si128(result1,result); //Nos quedamos con los que multiplicamos x dos.


multipli = _mm_mullo_epi32(multipli, registro2); //Multiplicamos x dos y obtenemos los ultimos 32 bits



suma = _mm_andnot_si128(result1,result); //A estos les sumamos 5.


suma =  _mm_add_epi32(suma,registro5); //Sumamos cinco

result1= _mm_or_si128(resta,suma);

result1 = _mm_or_si128(result1,multipli); //Unimos todas las soluciones

_mm_store_si128((__m128i*)&v[i], result1); //Devolvemos el resultado al arreglo.

}
 /*  for (i = 0; i < elementos; i++)
      if (v[i] > 50000000)
         v[i] = v[i] - 5;
      else if (v[i] < 10000000)
         v[i] = v[i] + 5;
      else

 v[i] = v[i] * 2;
*/
   printf("elemento 0: %d\n",v[0]);
   printf("elemento 499999999: %d\n",v[49999999]);
   printf("elemento 500000000: %d\n",v[50000000]);
   printf("elemento 999999999: %d\n",v[99999999]);
	free(v);


   return 0;
}
