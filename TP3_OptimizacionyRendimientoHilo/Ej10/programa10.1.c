#include <stdlib.h>
#include <stdio.h>

int main() {
    int i, elementos = 100000000;
    int *v;

    v = malloc(elementos * sizeof(int));

    // no vectorizar este for
    for (i = 0; i < elementos; i++)
        v[i] = i;

    for (i = 0; i < elementos; i++)
        if (v[i] > 50000000)
            v[i] = v[i] - 5;
        else
            v[i] = v[i] + 5;

    printf("elemento 0: %d\n", v[0]);
    printf("elemento 49999999: %d\n", v[49999999]);
    printf("elemento 50000000: %d\n", v[50000000]);
    printf("elemento 99999999: %d\n", v[99999999]);

    return 0;
}
