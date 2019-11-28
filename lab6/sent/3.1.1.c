// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 3.1.1.c
// atividade: 3.1.1


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int var = 0;
pthread_mutex_t posse;

void* contador ( void* arg ) {
    int *i = (int *) arg;

    pthread_mutex_lock(&posse);

    var++;
    // printf("Thread %d incrementou. Novo Valor: %d.\n", *i, var);

    pthread_mutex_unlock(&posse);
    pthread_exit(NULL);
}

int main (void) {
    pthread_t t[10];

    pthread_mutex_init(&posse, 0);
    
    for (int i = 0; i < 10; i++) {
        int *id;
        id = malloc(sizeof(int));
        *id = i;
        pthread_create(&t[i], NULL, contador, (int *) id);
    }

    pthread_mutex_lock(&posse);
    var++; // A main também irá incrementar
    // printf("Main incrementou. Novo Valor: %d.\n", var);
    pthread_mutex_unlock(&posse);

    for (int i = 0; i < 10; i++) {
        pthread_join(t[i], NULL);
    }

    return 0;
}