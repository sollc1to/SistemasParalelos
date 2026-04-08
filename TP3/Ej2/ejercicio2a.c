#include <stdio.h>

/*La idea de este ejercicio es que el siguiente código incompleto
haga menos trabajo optimizandolo.

int main(){

int flag = 0;

for (int i = 0; i<1000; i++){
if(complex_func(a[i]) < 55) 
flag = 1;

}

printf("¿Elemento encontrado? %d/n",flag);


return 0;

}

Para esto vamos a:
- Realizar menos iteraciones en la repetitiva.
- Realizar un while en vez de un for.
- Ejecutar en el main el código para evitar llamadas a funciones.
-Aplicar la complex_func ahi mismo en la repetitiva.
-Podriamos primero aplicar complex_func en el  arreglo y luego evaluar? 

*/


int main(){
int a[1000];

int flag = 0;
int i=0;
while (i < 1000 && flag != 1){
/* Suponemos que la complex_func realiza un calculo..*/

if (complex_func(a[i]) < 55){
flag = 1;


}

i++;

}


printf("¿Elemento encontrado? %d\n",flag);

return 0;

}
