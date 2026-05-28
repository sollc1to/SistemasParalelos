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

    int hilosDisponibles = 0;

#pragma omp parallel num_threads(12) shared(num_steps, step, pi, hilosDisponibles)

    {
        double x;

        // Variable privada para cada thread
        double sumaLocal = 0;

        int id = omp_get_thread_num();

        hilosDisponibles = omp_get_num_threads();

        int ini, final;

        int paso = num_steps / hilosDisponibles;

        ini = id * paso;
        final = (id + 1) * paso;

        for (int i = ini; i < final; i++)
        {
            x = (i + 0.5) * step;

            sumaLocal = sumaLocal + 4.0 / (1.0 + x * x);
        }

        // Sección crítica
#pragma omp critical
        {
            pi += sumaLocal;
        }
    }

    pi = pi * step;

    printf("%f\n", pi);

    t = sampleTime() - t;

    printf("Tiempo transcurrido: %f segundos\n", t);

    return 0;
}
