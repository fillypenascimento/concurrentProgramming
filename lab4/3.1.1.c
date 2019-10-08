// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 3.1.1.c
// atividade: 3.1.1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int contador = 0;
pthread_cond_t condespera;
pthread_mutex_t mutex;
void *carteiro(void *empty){
    pthread_mutex_lock(&mutex);
    printf("Sou o carteiro, daqui a 1 segundo eu volto\n");
    sleep(1);
    pthread_cond_signal(&condespera);
    pthread_mutex_unlock(&mutex);
}

void *cliente(void *args){
    int id = *((int *)args);
    pthread_mutex_lock(&mutex);
    printf("Sou o cliente %d\n", id);
    contador = contador + 1;
    if ((contador % 2) == 0){
         pthread_cond_wait(&condespera, &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t l, e[100];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condespera, NULL);
    int *id;
    pthread_t t[100];

    for (int i = 0; i < 30; i++){
        for(int j = 0; i<100; i++){
            *id = j;
            pthread_create(&e[i], NULL, cliente, (void *)id);
        }  
    }
    
    pthread_create(&l, NULL, carteiro, NULL);
    sleep(2);
    for (int i = 0; i < 30; i++) {
        for(int j = 0; i<100; i++){
            pthread_join(e[i],NULL);
        }
        
    }

    pthread_join(l, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condespera);
    return 0;
}
