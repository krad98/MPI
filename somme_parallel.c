// Adamou Walkao

/*
programme parrallel qui prend un tableau de 2 elements, pour chaque element du tableau fait l'addition à lui même 1.000.000.000 fois
puis remplace les elements du tableau par les valeurs retournés avec la fonction somme

execution avec 2 proccessus a donné un resultat de 2 sec:
    tab[2] = {1, 2}
    proccessus 0 reçoit 1 puis retourne 1.000.000.000 
    proccessus 1 reçoit 2 puis retourne 2.000.000.000
    
    temps d'execution 2.7 sec
*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int somme(int n);

int main(int argc, char **argv) {
    double start, end;
    int size, rank, n = 2;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int *globaldata=NULL;
    int localdata;

    if (rank == 0) {
        globaldata = malloc(n * sizeof(int) );
        for (int i=0; i<n; i++)
            globaldata[i] = i+1;

        printf("Processor %d has data: ", rank);
        for (int i=0; i<n; i++)
            printf("%d ", globaldata[i]);
        printf("\n");
    }

    start = MPI_Wtime();

    MPI_Scatter(globaldata, 1, MPI_INT, &localdata, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Processor %d has data %d\n", rank, localdata);
    int a = localdata;
    localdata = somme(a);
    printf("Processor %d multiplied the data, now has %d\n", rank, localdata);

    MPI_Gather(&localdata, 1, MPI_INT, globaldata, 1, MPI_INT, 0, MPI_COMM_WORLD);

    end = MPI_Wtime();

    if (rank == 0)
    {
        printf("Processor %d has data: ", rank);
        for (int i=0; i<n; i++)
            printf("%d ", globaldata[i]);
        printf("\n");

        printf("\nTemps: %f sec\n", end-start);

    }


    if (rank == 0)
        free(globaldata);

    MPI_Finalize();
    return 0;
}

int somme(int n)
{
    int x = 0;
    for (int i = 0; i < 1000000000; ++i)
    {
   
        x = x + n;

    }
    return x;
}
