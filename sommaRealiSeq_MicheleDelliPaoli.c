#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

void generateRandomNumber(int n, double *array){
	int i;
	srand((double) time(0));

	for(i=0; i<n; i++){
		array[i] = (float)rand()/RAND_MAX*5.0-2.0;
		if(n<20){
			printf("A[%d] = %f\n", i, array[i]); 
		}
	}

	return;
}

double computeSum(int n, double *array){
	int i;
	double result=0.0;
	for(i=0; i<n; i++){
		result += array[i];
	}
	return result;
}

int main (int argc, char **argv){
	
	int n;	
	double *array;
	double somma;
	double T_inizio,T_fine;

	MPI_Init(&argc,&argv);

	printf("Inserire il numero di elementi da sommare: \n");
	fflush(stdout);
	scanf("%d",&n);

	array = malloc(n*sizeof(double));
	
	generateRandomNumber(n, array);

	T_inizio = MPI_Wtime();

	somma = computeSum(n, array);

	T_fine = MPI_Wtime() - T_inizio;

	MPI_Finalize();
	
	printf("Somma: %f\n", somma);
	printf("Tempo di esecuzione in sequenziale: %lf\n", T_fine);

	return 0;
}
