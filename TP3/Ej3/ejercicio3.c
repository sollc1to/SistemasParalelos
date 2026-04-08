
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>


#define X 20000
#define Y 20000

int main(){

int i,j;
int **m = malloc(X*sizeof(int*));
int *x = malloc(X*Y*sizeof(int));
for(i = 0; i <X; i++)
m[i] = &x[i*Y];

for(i =0; i<X; i++){
for(j = 0; j<Y; j++){
m[i][j] = j%2;
}
}


/*struct rusage usage;
getrusage(RUSAGE_SELF, &usage);
printf("Memoria usada: %ld KB\n", usage.ru_maxrss);
*/
free(x);
free(m);
return 0;

}

