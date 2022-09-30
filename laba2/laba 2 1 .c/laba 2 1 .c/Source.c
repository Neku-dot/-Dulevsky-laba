#include<stdio.h>

float input_check();

int main()
{
	float initialCapital, finalCapital;
	int time = 0;

	printf("Input the sum - ");
	initialCapital = input_check();
	printf("Enter the final sum  - ");
	finalCapital = input_check();

	for (; initialCapital < finalCapital; time++)
		initialCapital += initialCapital * 0.04 / 12;
	printf("%d months", time);
}
float input_check()
{
	float input;
	while (scanf_s("%f", &input) == 0)
	{
		printf("Error input.\n");
		rewind(stdin);
	}
	return input;
}