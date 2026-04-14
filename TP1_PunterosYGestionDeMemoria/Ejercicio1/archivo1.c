
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
int a,b;
int *x, *y;
a = 10;
b = 20;
x = &a;
y=&b;
x =y;
*x=5;

printf("Direccion variable x: %p\n",&x);
printf("Direccion variable y: %p\n",&y);
printf("HOLA");
printf("Contenido variable x %p\n",x);
printf("Contenido variable y %p\n",y);


return 0;
}


