// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 2.1.1.c
// atividade: 2.1.1
 
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
 
#define TOTAL 5
#define DIREITA (id_filosofo + 1) % TOTAL
#define ESQUERDA (id_filosofo + TOTAL - 1) % TOTAL
#define PENSANDO 0
#define COMFOME 1
#define COMENDO 2
 
int estado[TOTAL];
pthread_t jantar[TOTAL];
pthread_mutex_t mutex;
pthread_mutex_t mux_filo [TOTAL];
 
void *filosofo(void *param);
void pegar_garfo(int id_filosofo);
void devolver_garfo(int id_filosofo);
void intencao(int id_filosofo);
void comer(int id_filosofo);
void pensar(int id_filosofo);
 
void *filosofo(void *vparam){
 
   int *id = (int *)(vparam);
 
   printf("Filósofo %d foi criado com sucesso\n", *(id));
 
   while(1){
 
      pensar(*(id));
      pegar_garfo(*(id));
      comer(*(id));
      devolver_garfo(*(id));
   }
 
   pthread_exit((void*)0);
}
 
void pegar_garfo(int id_filosofo){
 
   pthread_mutex_lock(&(mutex));
   printf("Filósofo %d está com fome\n", id_filosofo);
   estado[id_filosofo] = COMFOME;
   intencao(id_filosofo);
   pthread_mutex_unlock(&(mutex));
   pthread_mutex_lock(&(mux_filo[id_filosofo]));
}
 
void devolver_garfo(int id_filosofo){
 
   pthread_mutex_lock(&(mutex));
   printf("Filósofo %d está pensando\n", id_filosofo);
   estado[id_filosofo] = PENSANDO;
   intencao(ESQUERDA);
   intencao(DIREITA);
   pthread_mutex_unlock(&(mutex));
}
 
void intencao(int id_filosofo){
 
   printf("Filósofo %d está com intenção de comer\n", id_filosofo);
   if((estado[id_filosofo] == COMFOME) && (estado[ESQUERDA] != COMENDO) && (estado[DIREITA] != COMENDO)){
 
      printf("Filósofo %d ganhou a vez de comer\n", id_filosofo);
      estado[id_filosofo] = COMENDO;
      pthread_mutex_unlock(&(mux_filo[id_filosofo]));
   }
}
 
void pensar(int id_filosofo){
 
   printf("Filósofo %d está pensando\n", id_filosofo);
   sleep(1);
}
 
void comer(int id_filosofo){   
   printf("Filósofo %d está comendo\n", id_filosofo);
   sleep(rand() % 5);
}
 
int main(){
 
   int i;
 
   pthread_mutex_init( &(mutex), NULL);
   for(i= 0;i< TOTAL;i++){
      pthread_mutex_init(&(mux_filo[i]), NULL);
   }
 
   for(i=0;i< TOTAL;i++){
      pthread_create(&(jantar[i]), NULL, filosofo, (void *)&(i));
   }
 
   pthread_mutex_destroy(&(mutex));
   for(i=0;i<TOTAL;i++){
      pthread_mutex_destroy(&(mux_filo[i]));
   }
   pthread_exit(NULL);
 
   return 0;
}
