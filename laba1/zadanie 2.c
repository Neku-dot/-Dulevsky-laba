#include<stdio.h>
#include <locale.h>

int main()
{
	int x,x1,x2,x3,x4,x5,x6;
	scanf_s("%d", &x);
	x1 = x % 10;
	x = x / 10;
	x2 = x % 10;
	x = x / 10;
	x3 = x % 10;
	x = x / 10;
	x4 = x % 10;
	x = x / 10;
	x5 = x % 10;
	x6 = x / 10;
	
	if (x1 + x2 + x3 == x4 + x5 + x6) {
		printf("Happy ticket");

	}
	else {
		printf("Not happy ticket");
	}
	return 0;
}