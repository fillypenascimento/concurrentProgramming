// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 2.1.1.c
// atividade: 2.1.1

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<time.h>

int contabancaria = 0;
int turn = 1;

void *deposito(){
    while(turn != 1){}
    contabancaria+=20;
    printf("Efeuado depósito. Saldo: %d\n", contabancaria);
    turn = 2;
    pthread_exit(NULL);
}

void *retirada() {
    while(turn != 2){}
    if(contabancaria >= 10){
        contabancaria-=10;
    }
    printf("Efetuada retirada. Saldo: %d\n", contabancaria);
    turn = 1;
    // pthread_exit(NULL);
}

int main() {

    pthread_t t1,t2,t3;
    
    pthread_create(&t1, NULL, deposito, NULL);
    pthread_create(&t2, NULL, retirada, NULL);
    pthread_create(&t3, NULL, deposito, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}