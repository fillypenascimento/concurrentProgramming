#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv){
    int rank, size, valor, n, soma=0;
    int total_sum = 0, *values;
    const int root = 0;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        scanf("%d", &n);
        
        int aux;
        values = malloc(sizeof(int)*n);

        for(int i=0;i<n;i++){
            scanf("%d", &aux);
            values[i] = aux;
        }
    }

    int* n_subset = malloc(sizeof(int) * (n/size));

    MPI_Scatter(values,(n/size),MPI_INT,n_subset,(n/size),MPI_INT,0,MPI_COMM_WORLD);

    int partial_sum = 0;

    for(int j=0;j<(n/size);j++){
        partial_sum+=n_subset[j];
    }

    int* n_sub_total = NULL;

    if(rank == 0){
        n_sub_total = malloc(sizeof(int)*size);
    }

    MPI_Gather(&partial_sum,1,MPI_INT,n_sub_total,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank == 0){
        total_sum+=*n_sub_total;
    }

    printf("Processo %d. Valor: %d.\n", rank, total_sum);
    
    MPI_Finalize();
    return 0;
}