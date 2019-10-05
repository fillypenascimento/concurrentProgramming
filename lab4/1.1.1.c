#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t possedalista;
int assinaturas=0, *ass;

void *aluno(void *id) {
    int *i = (int *) id;

    pthread_mutex_lock(&possedalista);

    *(ass+assinaturas) = *i;
    assinaturas++;

    sleep(1);

    printf("Aluno %d assinou a lista.\n", *i);

    pthread_mutex_unlock(&possedalista);
}

int main() {
    int n;
    scanf("%d",&n);

    int tmp[n];
    ass = tmp;

    pthread_t t[n];
    
    pthread_mutex_init(&possedalista, 0);
    for (int i = 0; i < n; i++) {
        int *id;
        id = malloc(sizeof(int));
        *id = i;
        pthread_create(&t[i], NULL, aluno, (int *) id);

    }

    for (int i = 0; i < n; i++) {
        pthread_join(t[i], NULL);
    }

    printf("A ordem de assinatura da lista foi: "); 
    for(int i=0; i<n ;i++){
        printf("%d ", *(ass+i));
    }
    printf("\n");

    pthread_mutex_destroy(&possedalista);
    return 0;
}