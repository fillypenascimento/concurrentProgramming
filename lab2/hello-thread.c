// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: hello-thread.c
// atividade: 1.1.1

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void *rotina(){
	printf("Olá, sou uma thread\n");
	sleep(2);
}

int main(){
	pthread_t t;
	pthread_create(&t, NULL, rotina, NULL);
	pthread_create(&t, NULL, rotina, NULL);
	printf("Olá, sou a main.\n");
return 0;
}