#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void arr_rand_input(int arr[100][100], int size)
{
	srand(time(0));

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = rand() % 200 - 100;
}

void arr_input(int arr[100][100], int size)
{
	printf("input array:\n");

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf_s("%d", &arr[i][j]);
}

void arr_print(int arr[100][100], int size)
{
	printf("Array:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%4d ", arr[i][j]);
		printf("\n");
	}
}

int input_arraySize(int x)
{
	while (scanf_s("%d", &x) != 1 || x < 0 || x > 100 || x == 0)
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

int new_size(int size)
{
	if (size % 2 != 0)
		size++;
	return size;
}
void sum(int array[100][100], int N)
{
	int n = N,sum = 0, flag=0;
	for (int j = 0; j <= N / 2; j++)
	{
		for (int i = flag; i < n; i++)
		{
			sum += array[i][j];
		}
		n--;
		flag++;
	}
	printf("Sum of elements: %d", sum);
}
int main()
{
	int arr[100][100];
	int k = 1, size = 0, n = 0;

	n = choice_input_check(n);

	printf("Input Size of array:\n");

	printf("Size =");
	size = input_arraySize(size);

	if (n == 1)
	{
		arr_input(arr, size);
	}
	else if (n == 2)
	{
		arr_rand_input(arr, size);
	}
	arr_print(arr, size);
	sum(arr, size);
	return 0;
}