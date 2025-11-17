#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void *mensaje(void *arg)
{
    char *msg;
    msg = (char *)arg;
    printf("%s", msg);   
}
int main()
{
    pthread_t h1, h2, h3, h4;

    char *m1 = "Hilo 1: Hola, ";
    char *m2 = "Hilo 2: Soy";
    char *m3 = "Hilo 3: Fabio";
    char *m4 = "Hilo 4: Pillajo";

    pthread_create(&h1, NULL, mensaje, (void *)m1);
    pthread_join(h1, NULL);

    printf("\n");

    pthread_create(&h2, NULL, mensaje, (void *)m2);
    pthread_join(h2, NULL);

    printf("\n");

    pthread_create(&h3, NULL, mensaje, (void *)m3);
    pthread_join(h3, NULL);

    printf("\n");

    pthread_create(&h4, NULL, mensaje, (void *)m4);
    pthread_join(h4, NULL);

    printf("\n");

    return 0;
}
