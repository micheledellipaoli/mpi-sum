#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

void generateRandomNumber(int n, int *array){
	int i;
	srand((unsigned int) time(0));

	for(i=0; i<n; i++){
		array[i] = rand()%5-2;
	}

	return;
}

int computeSum(int n, int *array){
	int i;
	int result=0;
	for(i=0; i<n; i++){
		result += array[i];
	}
	return result;
}

int main (int argc, char **argv){
	
	int n;	
	int *array;
	int somma;
	double T_inizio,T_fine;

	MPI_Init(&argc,&argv);

	printf("Inserire il numero di elementi da sommare: \n");
	fflush(stdout);
	scanf("%d",&n);

	array = malloc(n*sizeof(int));
	
	generateRandomNumber(n, array);

	T_inizio = MPI_Wtime();

	somma = computeSum(n, array);

	T_fine = MPI_Wtime() - T_inizio;

	MPI_Finalize();
	
	printf("Somma: %d\n", somma);
	printf("Tempo di esecuzione in sequenziale: %lf\n", T_fine);

	return 0;
}
