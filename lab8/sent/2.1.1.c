#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
    int rank, np, valor1;
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    if (rank == 0) {
        scanf("%d", &valor1);
        MPI_Send(&valor1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Processo %d de %d enviando mensagem ao processo 1. Mensagem: %d.\n", rank, np, valor1);
        MPI_Recv(&valor1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        printf("Processo %d de %d recebeu mensagem do processo 1. Mensagem: %d.\n", rank, np, valor1);
    }
    else if (rank == 1) {
        MPI_Recv(&valor1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Processo %d de %d recebeu mensagem do processo 0. Mensagem: %d.\n", rank, np, valor1);
        MPI_Send(&valor1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        printf("Processo %d de %d enviando mensagem ao processo 0. Mensagem: %d.\n", rank, np, valor1);
    }

    MPI_Finalize();

    return 0;
}