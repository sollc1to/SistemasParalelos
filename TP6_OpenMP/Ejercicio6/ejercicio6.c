#include <stdio.h>
#include <unistd.h>
#include <time.h>
void trabajo(int id){
    printf("%d: Trabajo muy duro...\n", id);
    sleep(1);
    printf("%d: como un esclavo!\n", id);
    sleep(1);
}


double
sampleTime ()
{
  struct timespec tv;

  clock_gettime (CLOCK_MONOTONIC_RAW, &tv);

  return ((double) tv.tv_sec + ((double) tv.tv_nsec) / 1000000000.0);
}


int main(){

double t = sampleTime();

    trabajo(0);
    trabajo(1);
    trabajo(2);
    trabajo(3);
    trabajo(4);
    trabajo(5);
    trabajo(6);
    trabajo(7);


t = sampleTime() - t;
printf("Tiempo que tardo el programa %f",t);
    return 0;
}
