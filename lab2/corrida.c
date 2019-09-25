// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: corrida.c
// atividade: 4.1.2

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<time.h>

int largada = 3;

void *juizdelargada() {
    while(largada > 0){
        printf("%d\n", largada);
        largada--;
        srand(time(NULL));
        int ra = rand() % 10;
        sleep(ra);
    }
    printf("GO!\n");
    pthread_exit(NULL);
}

void *carro(void *ID) {
    if(largada == 0) {
        printf("Sou o carro %d e terminei a corrida.\n", ID);
        pthread_exit(NULL);
    }
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, juizdelargada, NULL);
    pthread_join(t, NULL);

    const int NUMTHREADS = 10;
    pthread_t threads[NUMTHREADS];
    for (long int i = 0; i < NUMTHREADS; i++) {
        pthread_create(&threads[i], NULL, carro, (void *) i);
    }
    for (long int i = 0; i < NUMTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }


    return 0;
}