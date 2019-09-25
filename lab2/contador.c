// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: contador.c
// atividade: 3.1.1

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>


void *contador(void *id){
  long int tid = (long int )id;
  int n = 1, i;
  while(n <= 5){
    printf("Sou a thread %ld e estou no número %d.\n", tid, n);
    n++;
  }
}

int main(){
  const int NUMTHREADS = 10;
  pthread_t threads[NUMTHREADS];
  for (long int i = 0; i < NUMTHREADS; i++) {
    pthread_create(&threads[i], NULL, contador, (void *) i);
  }
  for (long int i = 0; i < NUMTHREADS; i++) {
    pthread_join(threads[i], NULL);
  }
return 0;
}