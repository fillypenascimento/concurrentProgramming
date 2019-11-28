// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 1.1.c
// atividade: 1.1

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long long int somavalores(int *valores, int n){

    long long int soma = 0;
    for (int i = 0; i < n; i++) {
        soma = soma + valores[i];
    }
    
    return soma;
}

int main(){
    

    long long int i, n, soma;
    int *valores;

    // scanf("%lld", &n);
    n = 100000000;
    valores = (int *)malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++) {
        valores[i] = 1;
    }

    soma = somavalores(valores, n);
    printf("Soma: %lld - %s\n", soma, soma == n ? "ok" : "falhou");

    free(valores);

    return 0;
}