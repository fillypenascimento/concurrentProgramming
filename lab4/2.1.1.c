#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUMTHREADS 90

sem_t sala1, sala2, sala3;
pthread_mutex_t guias;

void *turista(void *args) {
    int id = *((int *)args) ;
    sem_wait(&sala1);
    pthread_mutex_trylock(&guias);
    sleep(2);
    sem_post(&sala1);

    sem_wait(&sala2);
    pthread_mutex_trylock(&guias);
    sleep(2);
    sem_post(&sala2);

    sem_wait(&sala3);
    pthread_mutex_trylock(&guias);
    sleep(2);
    sem_post(&sala3);

    
    printf("%d\n", id);
    
    sem_post(&sala2);
}

void *guia(){
    pthread_mutex_lock(&guias);
    int* value;

    sem_getvalue(&sala1,value);
    if(*value == 10){
        pthread_mutex_unlock(&guias);
    }

    sem_getvalue(&sala2,value);
    if(*value == 6){
        pthread_mutex_unlock(&guias);
    }

    sem_getvalue(&sala2,value);
    if(*value == 18){
        pthread_mutex_unlock(&guias);
    }
}

int main() {
    pthread_t t[NUMTHREADS], guia;
    int *id;

    sem_init(&sala1, 0, 10);
    sem_init(&sala2, 0, 6);
    sem_init(&sala3, 0, 18);
    sem_init(&guias, 0, 1);

    for (int i = 0; i < NUMTHREADS; i++) {
        id = (int *) malloc(sizeof(int));
        *id = i;
        pthread_create(&t[i], NULL, turista, NULL);
    }
    pthread_create(&guia, NULL, guia, NULL);

    for (int i = 0; i < NUMTHREADS; i++) {
        pthread_join(t[i], NULL);
    }

    sem_destroy(&semaforo);
    return 0;
}