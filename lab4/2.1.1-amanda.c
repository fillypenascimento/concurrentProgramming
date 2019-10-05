// autor: Amanda Oliveira Alves
// arquivo: 2.1.1.c
// ativnade: 2.1.1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUMTHREADS 10
#define SALA1 10
#define SALA2 6
#define SALA3 18


sem_t semaforo;
void *turista(void *args){
  int n = *((int *)args);
  sem_wait(&semaforo);
  sleep(2);
  printf("Sala %d completa, começando a explicação.\n", n);
  sem_post(&semaforo);
}

int main(){
  pthread_t t[NUMTHREADS];
  int *n;
  sem_init(&semaforo, 0, SALA1);
  for (int i = 0; i < NUMTHREADS; i++) {
    n = (int *) malloc(sizeof(int));
    *n = 1;
    pthread_create(&t[i], NULL, turista, (void *)n);
  }
  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_join(t[i], NULL);
  }
  sem_destroy(&semaforo);

  sem_init(&semaforo, 0, SALA2);
  for (int i = 0; i < NUMTHREADS; i++) {
    n = (int *) malloc(sizeof(int));
    *n = 2;
    pthread_create(&t[i], NULL, turista, (void *)n);
  }
  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_join(t[i], NULL);
  }
  sem_destroy(&semaforo);

  sem_init(&semaforo, 0, SALA3);
  for (int i = 0; i < NUMTHREADS; i++) {
    n = (int *) malloc(sizeof(int));
    *n = 3;
    pthread_create(&t[i], NULL, turista, (void *)n);
  }
  for (int i = 0; i < NUMTHREADS; i++) {
    pthread_join(t[i], NULL);
  }
  sem_destroy(&semaforo);
  return 0;
}