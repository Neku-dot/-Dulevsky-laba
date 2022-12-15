#include "Header.h"

int main()
{
    int n = 0;

    printf("Choice task that you want to check.\n");

    n = menu(n);

    switch (n)
    {
    case 1:
        task_1();
        break;
    case 2:
        task_2();
        break;
    case 3:
        task_3();
        break;
    default:
        printf("Not on the list");
        break;
    }
    return 0;
}