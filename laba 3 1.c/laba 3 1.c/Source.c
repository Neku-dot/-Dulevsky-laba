#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void array_input_check(int arr[], int SIZE);
void arr_rand_input(int arr[], int SIZE);
int input_check();
int find_max_elem(int arr[], int SIZE);
int arry_multiply(int arr[], int SIZE);
int choice_input_check();

int main()
{
	int arr[100], ARR_SIZE = 0, choice = 0;
	ARR_SIZE = input_check();
	choice = choice_input_check();
	switch (choice)
	{
	case 1:
		array_input_check(arr, ARR_SIZE);
		break;
	case 2:
		arr_rand_input(arr, ARR_SIZE);
		break;
	default:
		return 0;
		break;
	}
	printf("\npos elem %d\n", find_max_elem(arr, ARR_SIZE));
	printf("%d", arry_multiply(arr, ARR_SIZE));

}

int choice_input_check()
{
	int input;
	printf("Print 1 if you want to enter the elements manually or print 2 to fill the arry with  random numbers\n");
	while (scanf_s("%d", &input) != 1 || input > 2 || input < 1 || getchar() != '\n')
	{
		printf_s("Wrong input\n");
		rewind(stdin);
	}
	return input;
}

int input_check()
{
	int input;
	printf("Enter the arry size that is lies between 1 and 100\n");
	while (scanf_s("%d", &input) == 0 || input >= 101 || input <=0 || getchar() != '\n')
	{
		printf("Wrong input.\n");
		rewind(stdin);
	}
	return input;
}

void array_input_check(int arr[], int SIZE)
{
	printf("Enter the elments of arry\n");
	for (int i = 0; i < SIZE; i++)
	{
		while (scanf_s("%d", &arr[i]) == 0)
		{
			printf("Wrong input.\n");
			scanf_s("%i", &arr[i]);
			rewind(stdin);
		}
	}
}

void arr_rand_input(int arr[], int SIZE)
{
	srand(time(0));
	printf("Array = ");
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand()%4-2;
		printf("%d ", arr[i]);
	}
}

int find_max_elem(int arr[], int SIZE)
{
	int max_elem = arr[0], elem=0;
	for (int i = 0; i < SIZE; i++)
	{
		if (max_elem < arr[i])
		{
			max_elem = arr[i];
			elem = (i + 1);
		}
	}
	return elem;
}

int arry_multiply(int arr[], int SIZE)
{
	int multi = 1, first_zero = 0, second_zero = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			first_zero = i;
			break;
		}
	}
	for (int i = first_zero + 1; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			second_zero = i;
			break;
		}
	}
	if (second_zero != 0 && second_zero != first_zero + 1)
	{
		for (int i = first_zero + 1; i < second_zero; i++)
		{
			multi *= arr[i];
		}
		printf_s("Muliplication between 2 zero numbers is equal ");
		return multi;
	}
	else
	{
		if (second_zero == 0) printf_s("There are no 2 zero elements\n");
		else printf_s("There are no elements between 0 and 0\n");
		return 0;
	}
}