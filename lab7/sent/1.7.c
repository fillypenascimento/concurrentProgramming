// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 1.7.c
// atividade: 1.7

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long long int somavalores(int *valores, int n){

    long long int soma = 0;
    int i;

    #pragma omp parallel for private(i) reduction(+:soma)
    for (i = 0; i < n; i++) {
        soma += valores[i];
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

    double initialTime = omp_get_wtime();

    soma = somavalores(valores, n);
    printf("Soma: %lld - %s\n", soma, soma == n ? "ok" : "falhou");
    free(valores);

    double finalTime = omp_get_wtime();
    printf("Tempo de processamento: %lf segundos.\n", finalTime - initialTime);

    return 0;
}