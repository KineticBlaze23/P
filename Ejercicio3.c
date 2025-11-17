#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

struct timeval tinicio, tfin;
double promedio = 0.0;

void *hilo(void *arg)
{
    gettimeofday(&tfin, NULL);
    long diff = (tfin.tv_sec - tinicio.tv_sec) * 1000000L +
                (tfin.tv_usec - tinicio.tv_usec);
    promedio += diff;
    pthread_exit(NULL);
}

int main()
{
    pthread_t h;
    long i;
    //1 MILLÓN DE HILOS 
    promedio = 0.0;
    for (i = 0; i < 1000000; i++)
    {
        gettimeofday(&tinicio, NULL);
        pthread_create(&h, NULL, hilo, NULL);
        pthread_join(h, NULL);
    }
    printf("Tiempo total para 1,000,000 hilos: %.0f microsegundos\n", promedio);

    //2 MILLONES DE HILOS 
    promedio = 0.0;
    for (i = 0; i < 2000000; i++)
    {
        gettimeofday(&tinicio, NULL);
        pthread_create(&h, NULL, hilo, NULL);
        pthread_join(h, NULL);
    }
    printf("Tiempo total para 2,000,000 hilos: %.0f microsegundos\n", promedio);

    // 3 MILLONES DE HILOS 
    promedio = 0.0;
    for (i = 0; i < 3000000; i++)
    {
        gettimeofday(&tinicio, NULL);
        pthread_create(&h, NULL, hilo, NULL);
        pthread_join(h, NULL);
    }
    printf("Tiempo total para 3,000,000 hilos: %.0f microsegundos\n", promedio);

    return 0;
}
