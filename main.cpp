#include <mpi.h>
#include <iostream>
#define m 1
#define n 1000

int main(int argc, char **argv) {
    int mynode, totalnodes;
    int sum, startval, endval, accum;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);
    MPI_Comm_rank(MPI_COMM_WORLD, &mynode);

    sum = 0;
    startval = n * mynode / totalnodes + m;
    endval = n * (mynode + 1) / totalnodes;

    for (int i = startval; i <= endval; i++)
        sum += i;

    if (mynode != 0)
        MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    else {
        for (int j = 1; j < totalnodes; j++) {
            MPI_Recv(&accum, 1, MPI_INT, j, 1, MPI_COMM_WORLD, &status);
            sum += accum;
        }
        std::cout << "The sum is: " << sum << std::endl;
    }

    MPI_Finalize();
    return 0;
}
