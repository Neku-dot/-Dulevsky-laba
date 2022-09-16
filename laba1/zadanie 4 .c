#include<stdio.h>
int main()
{
    int  m;
    printf(" Choose : \n 1.Winter \n 2.Spring\n 3.Autom\n 4.Summer \n ");
    scanf_s("%d", &m);
    printf("Month : ");
    switch (m)
    {
    case 1:
        printf("December \n        January \n        February \n");
        break;
    case 2:
        printf("March \n        April \n        May \n");
        break;
    case 3:
        printf("September \n        October \n        November");
        break;
    case 4:
        printf("June \n        July \n        August \n ");
        break;
    default:
        printf("Not on the list");
        break;
    }
    return 0;
}

