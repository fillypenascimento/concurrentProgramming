// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 1.1.1.c
// atividade: 1.1.1

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<time.h>

int contador = 0;

void *incrementos() {
    for(int i=0;i<100;i++){
        contador++;
    }
    pthread_exit(NULL);
}

int main() {

    const int NUMTHREADS = 10;
    pthread_t threads[NUMTHREADS];
    for (long int i = 0; i < NUMTHREADS; i++) {
        pthread_create(&threads[i], NULL, incrementos, NULL);
    }
    for (long int i = 0; i < NUMTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", contador);

    return 0;
}