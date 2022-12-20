#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
void clear_memory(int** array, int n) {
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}
void memory(int*** array, int n, int m, int k)
{
    n++;
    if (k == 0)
    {
        *array = (int**)calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++)
        {
            (*array)[i] = (int*)calloc(m, sizeof(int));
        }
    }
    else
        clear_memory(*array, n);
}
void random1(int** array, int n, int m)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            array[i][j] = rand() % 100;
}
void print_array(int** array, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }

}

int array_sum(int** array, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int sum_array = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[j][i] % 2 == 0)
            {
                sum_array += array[j][i];
            }
        }
        array[n][i] = sum_array;
    }

}

void merge(int** array, int n, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
   
    int** L = (int**)calloc(n1, sizeof(int*));
    for (int q = 0; q < n1; q++) {
        L[q] = (int*)calloc(n + 1, sizeof(int));
    }
    int** R = (int**)calloc(n2, sizeof(int*));
    for (int q = 0; q < n2; q++) {
        R[q] = (int*)calloc(n + 1, sizeof(int));
    }


    for (i = 0; i < n1; i++) {
        for (int i1 = 0; i1 <= n; ++i1) {
            L[i][i1] = array[i1][l + i];
        }
    }
    for (j = 0; j < n2; j++) {
        for (int i1 = 0; i1 <= n; ++i1) {
            R[j][i1] = array[i1][m + 1 + j];
        }
    }
   
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i][n] <= R[j][n]) {
            for (int q = 0; q <= n; q++)
                array[q][k] = L[i][q];
            i++;
        }
        else {
            for (int q = 0; q <= n; q++)
                array[q][k] = R[j][q];
            j++;
        }
        k++;
    }

    while (i < n1) {
        for (int q = 0; q <= n; q++)
            array[q][k] = L[i][q];
        i++;
        k++;
    }

    while (j < n2) {
        for (int q = 0; q <= n; q++)
            array[q][k] = R[j][q];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int** array, int n, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(array, n, l, m);
        merge_sort(array, n, m + 1, r);

        merge(array, n, l, m, r);
    }
}
