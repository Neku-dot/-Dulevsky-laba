#include<stdio.h>

float input_check();

int main()
{
	float size1, size2;
	printf("Enter size in the 1 vessel ");
	size1 = input_check();
	printf("Enter size in the 2 vessel ");
	size2 = input_check();

	for (int i = 0; i < 12; i++)
	{
		size1 /= 2;
		size2 += size1;
		size2 /= 2;
		size1 += size2;
	}
	printf("The sum of water in the 1 vessel - %f\n", size1);
	printf("The sum of water in the 2 vessel - %f", size2);

}
float input_check()
{
	float input;
	while (scanf_s("%f", &input) == 0)
	{
		printf("Error.Enter the volume\n");
		rewind(stdin);
	}
	return input;
}