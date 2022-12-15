#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void arry_input_check(int arr[], int SZIE);
int input_check();
int choice_input_check();
void arr_rand_input(int arr[], int SIZE);
int even_delete(int arr[], int SIZE);

int main()
{
	int arr[100], ARR_SIZE = 0, choice = 0;
	
	ARR_SIZE = input_check();
	
	choice = choice_input_check();
	
	switch (choice)
	{
	case 1:
		arry_input_check(arr, ARR_SIZE);
		
		printf("\nArray: ");
		for (int i = 0; i < ARR_SIZE; i++)
			printf("%d ", arr[i]);
		printf("\n");
		break;
	
	case 2:
		arr_rand_input(arr, ARR_SIZE);
		printf("\nGenereted array: ");
		for (int i = 0; i < ARR_SIZE; i++)
			printf("%d ", arr[i]);
		printf("\n");
		break;
	
	default:
		return 0;
		break;
	}

	printf("\nFinal array: ");
	
	even_delete(arr, ARR_SIZE);
}

void arry_input_check(int arr[], int SIZE)
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

int input_check()
{
	int input;
	
	printf("Enter the arry size that is lies between 1 and 100\n");
	
	while (scanf_s("%d", &input) == 0 || input <= 0 || input > 100 || getchar() != '\n')
	{
		printf("Wrong input.\n");
		rewind(stdin);
	}
	
	return input;
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

int even_delete(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i + 1] % 2 == 0)
			continue;

		printf("%d ", arr[i]);
	}
}

void arr_rand_input(int arr[], int SIZE)
{

	srand(time(0));
	
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand()%201 - 101;
}