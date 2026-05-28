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

    int nthreads = 12;

    // Se agrega padding para evitar false sharing
    double suma[nthreads][8];

    for (int i = 0; i < nthreads; i++)
    {
        suma[i][0] = 0;
    }

    int hilosDisponibles = 0;

#pragma omp parallel num_threads(12) shared(num_steps, step, suma, hilosDisponibles)

    {
        double x;

        int id = omp_get_thread_num();

        hilosDisponibles = omp_get_num_threads();

        int ini, final;

        int paso = num_steps / hilosDisponibles;

        ini = id * paso;
        final = (id + 1) * paso;

        for (int i = ini; i < final; i++)
        {
            x = (i + 0.5) * step;

            suma[id][0] = suma[id][0] + 4.0 / (1.0 + x * x);
        }
    }

    for (int i = 0; i < hilosDisponibles; i++)
    {
        pi += suma[i][0];
    }

    pi = pi * step;

    printf("%f\n", pi);

    t = sampleTime() - t;

    printf("Tiempo transcurrido: %f segundos\n", t);

    return 0;
}
