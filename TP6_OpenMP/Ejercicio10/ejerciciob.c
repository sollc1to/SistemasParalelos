#include <stdio.h>


int main()
{

int i, x[1000];

for (i = 1; i<999;i++){
x[i+1] = x[i] + x[i-1];

}
//Este for no es paralelizable porque un proceso estaría
//intentando acceder a una posición de memoria anterior, la cuál estaría
//siendo modificada x otro proceso.  Dependencia RAW read after write. 


return 0;

}
