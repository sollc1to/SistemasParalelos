#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main(int argc, char **argv){
int id = 10;

#pragma omp parallel num_threads (10) private(id) 

{ 

id = omp_get_thread_num();
usleep(500);
printf("Soy el hilo %d de %d hilos...\n",id,omp_get_num_threads());
}

return 0;

}
