#include<stdio.h>

int input_check();

int main()
{
	int num1, num2, quotient = 0;
	printf("Enter the N number - ");
	num1 = input_check();
	printf("Enter the K number - ");
	num2 = input_check();
	for (; num1 >= num2; quotient++)
		num1 -= num2;
	printf("Division factor= %d\n", quotient);
	printf("The remainder of the division = %d", num1);
}

int input_check()
{
	int input;
	while (scanf_s("%i", &input) == 0)
	{
		printf("Error.Enter the number");
		rewind(stdin);
	}
	return input;
}