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
	printf("Array:\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d ", arr[i][j]);
		printf("\n");
	}
}

int input_arraySize(int x)
{
	while (scanf_s("%d", &x) != 1 || x < 0 || x > 100 || x==0 )
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

int main()
{
	int arr[100][100];
	int fl1 = 0, fl2 = 0, col = 0, row = 0, n = 0, max_elem;

	n = choice_input_check(n);

	printf("Input Size of array:\n");

	printf("row =");
	row = input_arraySize(row);

	printf("col =");
	col = input_arraySize(col);

	fl1 = col;

	if (n == 1)
	{
		arr_input(arr, col, row);
	}
	else if (n == 2)
	{
		arr_rand_input(arr, col, row);
	}
	arr_print(arr, col, row);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (arr[i][j] == 0)
			{
				fl1 -= 1;
				break;
			}
	}

	printf("number of rows without zero: %d\n", fl1);
	max_elem = find_max_elem(arr, row, col);
	if (max_elem == INT_MIN)
	{
		printf("There is no 2 or more same elements\n");
	}
	else
	{
		printf("Max elem : %d", find_max_elem(arr, row, col));
	}

	return 0;
}
int find_max_elem(int arr[100][100], int row, int col)
{
	int count = 2, max_elem = INT_MIN;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int temp = 0;
			for (int k = 0; k < row; k++)
			{
				for (int l = 0; l < col; l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						temp++;
					}
				}
			}
			if ((temp >= count) && (arr[i][j] > max_elem))
			{
				max_elem = arr[i][j];
			}
		}
	}
	return max_elem;
}