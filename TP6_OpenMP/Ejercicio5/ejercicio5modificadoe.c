#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <unistd.h>

double sampleTime()
{
    struct timespec tv;

    clock_gettime(CLOCK_MONOTONIC_RAW, &tv);

    return ((double) tv.tv_sec +
           ((double) tv.tv_nsec) / 1000000000.0);
}

int main()
{
    double t;

    t = sampleTime();

    long num_steps = 800000000;

    double step = 1.0 / (double) num_steps;

    double pi = 0;

#pragma omp parallel for num_threads(12) reduction(+:pi)

    for (long i = 0; i < num_steps; i++)
    {
        double x;

        x = (i + 0.5) * step;

        pi += 4.0 / (1.0 + x * x);
    }

    pi = pi * step;

    printf("%f\n", pi);

    t = sampleTime() - t;

    printf("Tiempo transcurrido: %f segundos\n", t);

    return 0;
}
