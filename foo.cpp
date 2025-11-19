#include <stdio.h>
#include <omp.h>
#include <iostream>

void sum(int N, int A[], int Y[])
{
	#pragma omp parallel for 
	for(int i=0; i<N; i++){
	for(int j=0; j<N; j++){
	Y[i] += A[i*N +j];
	}
	}
}
int main(int argc, char*argv[])
{
	int N=5;
	int A[N*N];
	int Y[N];

	for(int i=0; i<N*N; i++){
	A[i] = i%N;
	}

	for(int i=0; i<N; i++)
	{
	Y[i] = -1*i;
	}

	int threads = 0;
	#pragma omp parallel
	{
		#pragma omp single
		{
			threads = omp_get_num_threads();
			printf ("Using %d OpenMp threads\n",threads);
		}


	}

	sum (N,A,Y);

	printf("Contents of Y[] after sum():\n");
	for(int indx =0, i = 0; i<N; i++){
		printf(" %d", Y[indx++]);

	printf("\n");
	}
	int t = Y[0], err = 0,i;
	for(i=1; err ==00 && i<N ; i++){
		if(t!= Y[i])
		{
			err =1;
			printf(" correctness check fails at i=%d\n",i);
		}

		if (err == 0)
		{
		std::cout << "Correctness check succeeds " << std::endl;
		}
	}
}
