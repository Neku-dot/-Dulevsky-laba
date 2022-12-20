#include "Header.h"
int choice(int n)
{
    printf("\nChoice task\n1.Task 1\n2.Task 2 \n3.Leave\nYour choice:");
    int lastchar;

    while ((scanf_s("%d", &n)) != 1 || (n < 1 && n > 3) || ((lastchar = getchar()) != '\n' && lastchar != " "))
    {
        printf("Try again =)");
        rewind(stdin);
    }
    return n;
}

void input_string(char** string, int* lenght)
{
    *string = (char*)calloc(256, sizeof(char));
    char simb;
    int pos = 0;
    while (1)
    {
        simb = getchar();

        if (simb == '\n')
        {
            (*string)[pos] = '\0';
            *string = (char*)realloc(*string, (pos + 1) * sizeof(char));
            break;
        }
        (*string)[pos] = simb;
        pos++;
        *lenght = pos;
        if (pos >= 256)
            *string = (char*)realloc(*string, pos + 1 * sizeof(char));
    }

}



void swap_word(char* string)
{
    int i = 0, number_word = 0, size_word = 0,tmp2;
    int k = 0;
    int q = 1;
    char tmp;
    k = input_delete_num(k);
    while (string[i] != '\0')
    {
        if ((i==0 && if_letter(string[i]) == 1) || (if_letter(string[i]) == 1 && if_letter(string[i-1]) == 0))
        {
                number_word++;
            if (number_word == k)
            {
                int j = i;
                while (if_letter(string[j]) == 1)
                {
                    size_word++;
                    j++;
                }
                j--;
                tmp2 = j - i;
                if (size_word % 2 == 0)
                    while (tmp2 != 2)
                    {
                        tmp = string[i];
                        string[i] = string[j];
                        string[j] = tmp;
                        j--;
                        i++;
                        tmp2--;
                    }
                else
                    while (tmp2 != 1)
                    {
                        tmp = string[i];
                        string[i] = string[j];
                        string[j] = tmp;
                        j--;
                        i++;
                        tmp2--;

                    }
                
            }

        }
        i++;

    }
}

int input_delete_num(int n)
{
    int lastchar;
    printf("\nWhat word do you want to transponate:\n");
    while ((scanf_s("%d", &n)) != 1 || ((lastchar = getchar()) != '\n' && lastchar != " "))
    {
        printf("Try again =)");
        rewind(stdin);
    }
    return n;
}

int if_letter(char string)
{
    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z'))
        return 1;
    return 0;
}
void task_1()
{
    char* string;
    int lenght = 0, delete_num = 0;

    printf("Enter string:\n");
    input_string(&string, &lenght);

    printf("Entered string:\n");
    printf("%s", string);

    swap_word(string);

    printf("Final string:\n");
    printf("%s", string);

    string = (char*)calloc(0, 1);
}

char input_char(char c)
{
    printf("\nInput one symbole:\n");
    scanf_s("%c", &c);

    return c;
}

void input_string2_before_symbol(char** string, int lenght,int lenght2,char *string2)
{
    int i = 0, j = 0, cnt = 1, tmp,tng=lenght+lenght2;
    char c = 0;
    c = input_char(c);

    for (i = 0; (*string)[i] == c; i++) cnt++;
    (*string) = (char*)realloc(*string, (lenght + (lenght2) * (cnt) + 1) * sizeof(char));
    (*string)[lenght + (lenght2 * cnt)] = '\0';

    cnt = 1;
    i = 0;
    while ((*string)[i] != '\0')
    {
        
        if ((*string)[i]==c)
        {
            int p = i;
            for (int k = 0; k < lenght2; k++)
            {
                for (j = tng; j > p; j--)
                {
                
                    (*string)[j] = (*string)[j-1];
                    tng++;
                    

                }
                p++;
            }
            tng = 0; cnt++;
            tng = (lenght + (lenght2 * cnt) - 1);
            for (int h = 0; h < lenght2; h++)
                (*string)[i++] = string2[h];
            
        }
        i++;
    }
}

void task_2()
{
    char* string,*string2;
    int lenght = 0,lenght2;
    char c = '\0';

    printf("Input string:\n");
    input_string(&string, &lenght);

    //printf("Entered string:\n");
    //printf("%s", string);
    printf("\nInput second string to enter:\n");
    input_string(&string2, &lenght2);
    printf("%s", string2);

    input_string2_before_symbol(&string, lenght, lenght2,string2);

    printf("Final string:\n");
    printf("%s", string);

    string = (char*)calloc(0, 1);
    string2 = (char*)calloc(0, 1);
}

void stop()
{
    exit(EXIT_SUCCESS);
}