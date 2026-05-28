#include  <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>




int primo(int n) {
   int i,res,mitad;
   i = 2;
   res = 1;
   mitad = n / 2;
   while(res != 0 && i <= mitad) {
      res = n % i;
    	 i++;
   }
   return res;
}

int main(int argc, char *argv[]){

int inicio, fin, res = 0;
int cantidadPrimos = 0;
inicio = atoi(argv[1]);
fin = atoi(argv[2]);


#pragma omp parallel num_threads(12) shared(inicio, fin) private(res) reduction(+:cantidadPrimos)
{
int id =  omp_get_thread_num();
double tiempo = omp_get_wtime();

#pragma omp for schedule(guided) nowait 
for(int i = inicio; i < fin+1;i=i+1){
res = primo(i);

if(res == 1){
cantidadPrimos++;
}

}

tiempo = omp_get_wtime() - tiempo;
printf("El hilo numero %d termino su ejecucion tardando %f segundos\n",id,tiempo);





}


printf("Cantidad total de primos: %d\n", cantidadPrimos);


return 0;

}


