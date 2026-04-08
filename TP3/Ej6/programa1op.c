#include <stdio.h>

int main() {
    register int i, j, aux1, aux2;
    register int a = 0, a1 = 0, a2 = 0, a3 = 0;

    for (i = 0; i < 1000; i++) {
	aux1 = i*i*i;

        for (j = 0; j < 1000000; j += 4) { 
	    aux2 = aux1 +j;	 
	    a  += aux2;
            a1 += aux2 + 1;
            a2 += aux2 + 2;
            a3 += aux2+ 3;
        }
    }

    a = a + a1 + a2 + a3;

    printf("El valor calculado es: %d\n", a);

    return 0;
}
