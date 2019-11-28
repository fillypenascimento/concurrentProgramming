#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
    int rank, size, valor;
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        scanf("%d", &valor);
        MPI_Send(&valor, 1, MPI_INT, 1, 14, MPI_COMM_WORLD);
        printf("Processo %d de %d enviando mensagem ao processo 1. Mensagem: %d.\n", rank, size-1, valor);
        MPI_Recv(&valor, 1, MPI_INT, size-1, 14, MPI_COMM_WORLD, &status);
        printf("Processo %d de %d recebeu mensagem do processo %d. Mensagem: %d.\n", rank, size-1, size-1, valor);
    }
    else {
        MPI_Recv(&valor, 1, MPI_INT, rank-1, 14, MPI_COMM_WORLD, &status);
        printf("Processo %d de %d recebeu mensagem do processo %d. Mensagem: %d.\n", rank, size-1, rank-1, valor);
        valor+=1;
        MPI_Send(&valor, 1, MPI_INT, (rank+1)%size, 14, MPI_COMM_WORLD);
        printf("Processo %d de %d enviando mensagem ao processo %d. Mensagem: %d.\n", rank, size-1, (rank+1)%size, valor);
    }

    MPI_Finalize();

    return 0;
}