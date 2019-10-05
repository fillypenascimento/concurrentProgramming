#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUMTHREADS 1

pthread_cond_t condespera;
pthread_mutex_t mutex;

void *liberador(void *empty){
    pthread_mutex_lock(&mutex);
    printf("Sou o incrementador. Daqui um segundo, libero o esperador\n");
    sleep(1);
    pthread_cond_signal(&condespera);
    pthread_mutex_unlock(&mutex);
}

void *esperador(void *empty) {
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&condespera, &mutex);
    printf("Sou o esperador e já esperei.\n");
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t l, e;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condespera, NULL);
    printf("Criando o esperador.\n");
    pthread_create(&e, NULL, esperador, NULL);
    printf("Dormindo 2 segundos antes de criar o incrementador.\n");
    sleep(2);
    pthread_create(&l, NULL, liberador, NULL);
    pthread_join(l, NULL);
    pthread_join(e, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condespera);
    return 0;
}