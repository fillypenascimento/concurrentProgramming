// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: funcao.c
// atividade: 2.1.1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *quadratica(void *x) {
    double *result = malloc(sizeof(double));
    *result = 10 * *(double *)x * *(double *)x;
    pthread_exit(result);
}

void *cubica(void *x) {
    double *result = malloc(sizeof(double));
    *result = 42 * *(double *)x * *(double *)x * *(double *)x;
    pthread_exit(result);
}

int main() {
    pthread_t t1, t2;
    double x;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    void *r1, *r2;
    pthread_create(&t1, NULL, quadratica, (int *)&x);
    pthread_create(&t2, NULL, cubica, (int *)&x);
    pthread_join(t1, &r1);
    pthread_join(t2, &r2);
    double result = *(double *)r1 + *(double *)r2;
    printf("f(%.4f)= %.4f\n", x, result);
    free(r1);
    free(r2);
    return 0;
}