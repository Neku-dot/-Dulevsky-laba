#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <math.h>

int main()
{
	double a, b;
	setlocale(LC_ALL, "Rus");
	printf("������� ����� �������: ");
	scanf_s("%lf %lf", &a, &b);
	printf("���������� - %lf", sqrt(a * a + b * b));
	printf("\n������� - %lf", (a * b / 2));
	return 0;
}