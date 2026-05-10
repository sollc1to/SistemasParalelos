#include <emmintrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <smmintrin.h>		//Para la multiplicacion


int
main ()
{

  int i, elementos = 1000005;
  int *v, aux = elementos - (elementos % 4);	//Con este indice recorremos con funciones vectoriales.
  __m128i carga, registroDeDos, comparar, multipli, resultC, mayor, menor,
    dosNegativo;
multipli = _mm_setzero_si128();
  
carga = _mm_setzero_si128 ();

  registroDeDos = _mm_set1_epi32 (2);

  dosNegativo = _mm_sub_epi32 (carga, registroDeDos);



  v = malloc (elementos * sizeof (int));

  // no vectorizar este for
  for (i = 0; i < elementos; i++)
    v[i] = rand () % 10000;

  printf ("v[0]=%11d, ", v[0]);
  printf ("v[11]=%11d, ", v[11]);
  printf ("v[elementos-1]=%11d\n", v[elementos - 1]);

  for (i = 0; i < aux; i += 4)
    {
      carga = _mm_load_si128 ((__m128i *) & v[i]);

      comparar = _mm_set1_epi32 (i * 10);

      multipli = _mm_mullo_epi32 (carga, registroDeDos);	//Multiplicamos por dos y nos quedamos con los 32 bits mas bajos.

      resultC = _mm_cmpgt_epi32 (multipli, comparar);	//la multiplicacion es mayor a comparar??
//Si es mayor, tenemos que restarle 2 y multiplicar por -2.
//Si es menor, lo multiplicamos por dos.


      mayor = _mm_and_si128 (resultC, carga);	//A estos debemos restarle 2 y multiplicar por -2.


      menor = _mm_andnot_si128 (resultC, multipli);	//A estos solo los dejamos asi.


      mayor = _mm_sub_epi32 (mayor, registroDeDos);	//Le restamos dos.


      mayor = _mm_mullo_epi32 (mayor, dosNegativo);	//Multiplicamos por dos negativo.


      carga = _mm_or_si128 (mayor, menor);	//Unimos las dos soluciones.


      _mm_store_si128 ((__m128i *) & v[i], carga);	//Guardamos la solucion en el vector.


    }


//Hacemos lo que nos quedo escalarmente.


  for (aux; aux < elementos; aux++)
    {
      if (2 * v[aux] < aux * 10)
	v[aux] = v[aux] * 2;
      else
	v[aux] = (v[aux] - 2) * -2;
    }




  printf ("v[0]=%11d, ", v[0]);
  printf ("v[11]=%11d, ", v[11]);
  printf ("v[elementos-1]=%11d\n", v[elementos - 1]);

  return 0;
}
