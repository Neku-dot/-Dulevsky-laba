#include<stdio.h>
#include <locale.h>
int main()
{
	long double a, b, c;
	printf("Input 3 numbers \n");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	if (a - (int)a == 0) {
		printf("%.0lf Integer\n", a);
	} else {
		printf("%lf float\n", a);
	}
	if (b - (int)b == 0) {
		printf("%.0lf Integer\n", b);
	} else {
		printf("%lf float\n", b);
	}

	if (c - (int)c == 0) {
		printf("%.0lf Integer\n ", c);
	} else { 
		printf("%lf float\n", c);
	}

	return 0;
}