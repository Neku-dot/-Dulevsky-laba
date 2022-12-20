#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
void input(int *k)
{
	int p;
	while (scanf_s("%d", &p) != 1 || getchar() != '\n')
	{
		printf("Error,try againg");
		rewind(stdin);
	}
	*k = p;
}
void size_of_matrix(int *n,int *m)
{
	int N=0, M=0;
	printf("imput number of rows: ");
	input(&N);
	printf("imput number of colones: ");
	input(&M);
	*n = N; *m = M;

}
int main()
{
	int** array,N,M;
	size_of_matrix(&N, &M);
	memory(&array,N,M,0);
	random1(array, N, M);
	print_array(array, N, M);
	array_sum(array,  N, M);
	printf("\nSum of elements of each colo in the last row:\n\n");
	print_array(array, N + 1, M);
	merge_sort(array, N, 0, M - 1);
	printf("\nSorted array:\n");
	print_array(array, N + 1, M);
	memory(&array, N, M, 1);
	return 0;
}