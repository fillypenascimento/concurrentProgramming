#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
    int rank, size, namelen;
    char name[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_processor_name(name, &namelen);
    
    printf("%d (%s) de %d - Ola, MPI.\n", rank, name, size);
    
    MPI_Finalize();
    
    return 0;
}