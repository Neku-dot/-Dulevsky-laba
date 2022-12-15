#include "Header.h"

int menu(int n)
{
	printf("1.Task number one.\n2.Task number two.\n3.Task number three.\nYour choice: ");

	while (scanf_s("%d", &n) < 1 || (n != 1 && n != 2 && n != 3) || getchar() != '\n')
	{
		printf("Try again =)\n");
		rewind(stdin);
	}

	return n;
}
void delete_element(int** array, int* size, int index)
{
	*size = *size - 1;

	for (int i = index; i < *size; i++)
		(*array)[i] = (*array)[i + 1];

	*array = (int*)realloc((*array), (*size) * sizeof(int));
}

void fill_array_task1(int* array, int size)
{
	for (int i = 0; i < size; i++)
		*(array + i) = i + 1;
}

void memory_task1(int** array, int size)
{
	*array = (int*)calloc(size, sizeof(int));
}

void print_array_task1(int* array, int size)
{
	for (int i = 0; i < size; i++)
		printf("%4d ", *(array + i));
}

void multiple11_task1(int** array, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		if ((*array)[i] % 11 == 0)
			delete_element(array, size, i);
	}
}

void elem_write(int element, int size, int* arr)
{
	for (int i = 0; i < size; i++)
	{
		printf("Enter the %d element of the array\n", i);
		while (!scanf_s("%d", &arr[i]) || getchar() != '\n')
		{
			rewind(stdin);
			printf("Invalid data type\n");
		}
	}
}

int* rem_element(int* arr, int pos, int size)
{
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	free(arr);
	arr = temp;
	return temp;
}
int random()
{
	int x;
	while (!scanf_s("%d", &x) || x != 1 && x != 2)
	{
		printf("Invalid data type\n");
		rewind(stdin);
	}
	return x;
}
void print_array(int* x, int* y)
{
	for (int i = 0; i < x; i++)
		printf("%d; ", y[i]);
}
void rand_elem(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 300 - 150;
	}
}

void dimension(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x <= 0)
	{
		rewind(stdin);
		printf("Invalid data type\n");
	}
}

void task_1()
{
	int rands = -1;
	int elem = 0;
	int* array = NULL;
	int size = 0;
	printf("Enter array dimension:\n");
	dimension(&size);
	array = (int*)calloc(size, sizeof(int));
	printf("If you want to continue typing manualy, type '1'\n If you want to randomly generate numbers type '2'\n");
	rands = random();
	if (rands == 1)
	{
		elem_write(elem, size, array);
	}
	else if (rands == 2)
	{
		rand_elem(array, size);
	}
	printf("Your array: ");
	print_array(size, array);

	multiple11_task1(&array, &size);

	printf("\nReceived array:\n");
	print_array(size, array);

	free(array);
}

int* rem_element_matrix(int* arr, int pos, int size)
{
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	arr = temp;
	return temp;
}

void print_low(int row, int** arr)
{
	for (int i = 0; i < row; i++)
	{
		printf("\n");
		for (int n = 0; arr[i][n] != 0; n++)
			printf("%d; ", arr[i][n]);
	}
}


//TASK 2
int** memory_allocation(int x)
{
	int** arr = (int**)(malloc(x * sizeof(int*)));
	return arr;
}

int** search_max(int** arr, int size, int max, int num)
{
	int gretest = arr[num][0];
	for (int i = 0; i < size; i++)
	{
		if (arr[num][i] > gretest && arr[num][i] != 0)
		{
			max = i;
			gretest = arr[num][i];
		}
	}
	return max;
}

void print_array_task2(int** array, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d", array[i][j]);
		printf("\n");
	}
}

int* write_num(int number, int* size)
{
	*size = 0;
	int* temp = (int*)malloc(sizeof(int));
	int i = 0;
	while (1) {
		int entered;
		printf_s("Enter array element\n");
		while (!scanf_s("%d", &entered) || getchar() != '\n') {
			printf_s("Invalid data type\n");
			rewind(stdin);
		}
		temp[i] = entered;
		(*size)++;
		i++;
		temp = (int*)realloc(temp, (i + 1) * sizeof(int));
		if (entered == number) 
			break;
	}
	return temp;
}

void task_2()
{
	int max = 0, row, size, stop;
	int** array = NULL;
	printf("Enter the number of rows in the array:");
	dimension(&row);
	array = memory_allocation(row);
	int* sizes = (int*)malloc(row * sizeof(int));
	for (int i = 0; i < row; i++)
	{
		printf("Enter the elements of the %dth row\n", i);
		array[i] = write_num(0, &size);
		sizes[i] = size-1;
	}
	for (int i = 0; i < row; i++)
	{
		print_array_task1(array[i], sizes[i]);
		printf("\n");
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			max = search_max(array, sizes[j], max, j);
			array[j] = rem_element(array[j], max, sizes[j]);
		}
	}
	printf("\nResult:\n");
	print_low(row, array);
	free(array);
}

//TASK 3

void rand_array_task3(int*** array, int col, int row)
{
	*array = (int**)calloc(row, sizeof(int*));

	for (int i = 0; i < row; i++)
		(*array)[i] = (int**)calloc(col, sizeof(int*));

	srand(time(0));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			(*array)[i][j] = rand() % 2;
		}
	}
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

void manually(int*** arr, int row, int col)
{
	*arr = (int**)calloc(row, sizeof(int*));

	for (int i = 0; i < row; i++)
		(*arr)[i] = (int**)calloc(col, sizeof(int*));

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			printf_s("\nWrite element at pos (%d, %d): ", i, j);

			int number;

			while (!scanf_s("%d", &number) || getchar() != '\n') {

				printf_s("Invalid number!\n");

				rewind(stdin);

			}

			(*arr)[i][j] = number;

		}

	}

}

void choice_task3(int **arr, int row, int col) {
	int choice = 0;
	choice = choice_input_check(choice);
	if (choice == 1)
		manually(&arr, row, col);
	else if (choice == 2)
		rand_array_task3(&arr, row, col);


}

void print_array_task3(int** array, int row, int col)
{
	int fl = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d", array[i][j]);

		printf("\n");
	}
}

int size_input_check_task3(int n)
{
	int lastchar;

	while (scanf_s("%d", &n) != 1 || ((lastchar = getchar()) != '\n') && lastchar != ' ')
	{
		printf("Try again =)");
		rewind(stdin);
	}

	return n;
}

int amount_task3(int row, int col)
{
	int amount;

	amount = (row * col);

	if (col >= row)
		for (int i = 1; i < (row + 1); i++)
			amount -= i;

	else
		for (int i = 0; i < col; i++)
			amount -= row - i;

	return amount;
}

void free_array(int** array, int row)
{
	for (int i = 0; i < row; i++)
		free(array[i]);
	free(array);
}


void check_element_task3(int** array, int row, int col)
{
	int s = 0, n = 0, fl = -1, amount = 0;

	amount = amount_task3(row, col);

	for (int i = 0; i < row; i++, n++)
	{
		for (int j = n + 1; j < col; j++)
		{
			for (int k = 0; k < row; k++, s++)
			{
				for (int l = s + 1; l < col; l++)
				{
					if (array[i][j] == array[k][l])
						fl++;

					amount -= fl;
				}
			}
		}
	}

	printf("\n%d", amount);
}


void delete_row(int*** array, int* row, int col, int l)
{
	(*row)--;
	for (int i = l; i < *row; i++)
		for (int j = 0; j < col; j++)
			(*array)[i][j] = (*array)[i + 1][j];

	(*array) = (int**)realloc((*array), (*row) * sizeof(int*));
}
void task_3()
{
	int** array;
	int col = 0, row = 0;

	printf("Input size:\n");

	printf("row =");
	row = size_input_check_task3(row);

	printf("\ncol =");
	col = size_input_check_task3(col);

	choice_task3(&array, row, col);

	rand_array_task3(&array, col, row);

	printf("\nArray:\n");
	print_array_task3(array, row, col);

	int how_zero = 0, k = 0;
	for (int i=0 ;i<row ;i++){
		how_zero = 0;
		for (int j = 0; j < col; j++)
			if (array[i][j] == 0)
			{
				how_zero++;
				if (j <= col - 2)
					if (array[i][j + 1] == array[i][j] && array[i][j + 2] == array[i][j])
					{
						k = j;
						printf("k = [%d]", k);
					}
			}
		if (how_zero > 2)
			if (array[i][k] == array[i][k + 1] && array[i][k] == array[i][k + 2])
			{
				delete_row(&array, &row, col, i, k);
				printf("l = [%d]", i);
			}
	}
	printf("\nnew arr:\n");
	print_array_task3(array, row, col);

	free_array(array, row);
}
