#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void arr_rand_input(int arr[100][100], int col, int row)
{
	srand(time(0));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = rand() % 200 - 100;
}

void arr_input(int arr[100][100], int col, int row)
{
	printf("input array:\n");

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			scanf_s("%d", &arr[i][j]);
}

void arr_print(int arr[100][100], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d ", arr[i][j]);
		printf("\n");
	}
}

int input_arraySize(int x)
{
	while (scanf_s("%d", &x) != 1 || x < 0 || x > 100||x==0)
	{
		printf_s("Wrong input\n");
		rewind(stdin);
	}
	return x;
}

int choice_input_check(int n)
{
	printf("Print 1 if you want to enter the elements manually or print 2 to fill the arry with  random numbers\n");
	while (scanf_s("%d", &n) != 1 || (n != 1 && n != 2))
	{
		printf_s("Wrong input\n");
		rewind(stdin);
	}
	return n;
}
void sort_array(int lin, int col, int array[100][100])
{
	int itr = 0, fl;

	for (int i = 0; i < lin; i++)
	{
		for (int j = 0; j < col; j++)
			if (array[i][j] > array[i][j + 1])
			{
				while (itr < col)
				{
					for (int j = 0; j < col-1; j++)
						if (array[i][j] > array[i][j + 1])
						{
							int buf = array[i][j];
							array[i][j] = array[i][j + 1];
							array[i][j + 1] = buf;
						}

					itr++;
				}
			}
	}
}

int main()
{
	int arr[100][100];
	int  col = 0, row = 0, n = 0;

	n = choice_input_check(n);

	printf("Input Size of array:\n");

	printf("row =");
	row = input_arraySize(row);

	printf("col =");
	col = input_arraySize(col);

	if (n == 1)
		arr_input(arr, col, row);

	else if (n == 2)
		arr_rand_input(arr, col, row);

	printf("Array:\n");
	arr_print(arr, col, row);

	sort_array(row, col, arr);

	printf("Sorted array:\n");
	arr_print(arr, col, row);
}

