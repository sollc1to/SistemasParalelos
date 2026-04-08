#include <stdio.h>
/* Tenemos que optimizar el siguiente codigo 
int main(){
float i,j,a;
for(i =0; i<1000; i++){
	for (j=0; j<1000000;j++){
	a = i+j;
	}
}

return 0;

} */


int main(){
float i,j,a;

for(i =0; i<1000; i+=2){

	for (j=0; j<1000000;j+=2){
	a = i+j;
	a = i + (j+1);
	a = (i+1) +j;
	a= (j+1) + (i+1);
	}


}



return 0;

}
