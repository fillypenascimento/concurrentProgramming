#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
    int rank, size, valor;
    const int root = 0;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){
        scanf("%d", &valor);
    }

    MPI_Bcast(&valor,1,MPI_INT,root,MPI_COMM_WORLD);


    printf("Processo %d. Valor: %d.\n", rank, valor);
    
    MPI_Finalize();
    return 0;
}