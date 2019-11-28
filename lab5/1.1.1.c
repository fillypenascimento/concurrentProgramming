#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
 
#define ESCRITORES 3
#define LEITORES 10
 
int i, j, rc, total;
char vetor[10000];
char increment[1000];
sem_t mutex;
pthread_mutex_t bd;

void read_data_base();
void use_data_read();
void think_up_data();
void write_data_base();

void *reader(void *j){
  int i= *(int*) j;
  while(1){
    sem_wait(&mutex);
    rc=rc+1;
    if(rc==1) pthread_mutex_lock(&bd);
    sem_post(&mutex);
    read_data_base(i);
    sem_wait(&mutex);
    rc=rc-1;
    if(rc==0) pthread_mutex_unlock(&bd);
    sem_post(&mutex);
    use_data_read(i);
    sleep(rand() % 3);
  }
}
 
void *writer(void *j){
  int i= *(int*) j;
  while(1){
    think_up_data(i);
    pthread_mutex_lock(&bd);
    write_data_base(i);
    pthread_mutex_unlock(&bd);
    sleep(rand() % 2);
  }
}
 
void read_data_base(int i){
  printf("Leitor %d lê: %s\n",i,vetor);
}
 
void use_data_read(int i){
  printf("Leitor %d usa o que leu.\n",i);
}
 
void think_up_data(int i){
  printf("Escritor %d inventa um dado.\n",i);
  increment[0]='A';
  increment[1]= i;
}
 
void write_data_base(int i){
  strcat(vetor,increment);
  printf("Escritor %d: %s\n",i,vetor);
}  
 
int main(){
 
  rc=0;
  pthread_t writerthreads[ESCRITORES], readerthreads[LEITORES];
  sem_init(&mutex,0,1);
  pthread_mutex_init(&bd,NULL);
 
  for(i=0;i<ESCRITORES;i++){
    pthread_create( &writerthreads[i], NULL, writer, &i);
  }
 
  for(i=0;i<LEITORES;i++){
    pthread_create( &readerthreads[i], NULL, reader, &i);
  }

  for(i=0;i<ESCRITORES;i++){
    pthread_join(writerthreads[i], NULL);
  }

  for(i=0;i<LEITORES;i++){
    pthread_join(readerthreads[i], NULL);
  }

  return(0);
}
