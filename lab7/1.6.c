// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: 1.6.c
// atividade: 1.6

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long long int somavalores(int *valores, int n){

    long long int soma = 0;
    int i;

    omp_set_num_threads(2);

    #pragma omp parallel private(i)
    {
        long long int soma_parcial = 0;
        int id = omp_get_thread_num();
        printf("thread number: %d\n", id);
        #pragma omp for private(i)
        for (i = 0; i < n; i++) {
            soma_parcial = soma_parcial + valores[i];
        }
        #pragma omp atomic
        soma+=soma_parcial;
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