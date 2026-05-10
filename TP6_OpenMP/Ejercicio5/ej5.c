#include <omp.h>
#include <stdio.h>

int main(){
	omp_set_dynamic(0);
	#pragma omp parallel 
	{
		printf("hola\n");
		printf("chau\n");
	}
	
	printf("\n\nsiguiente region\n\n");
	omp_set_num_threads(5);
	#pragma omp parallel
	{
		printf("hola\n");
		printf("chau\n");
	}

	printf("fin\n");
}
