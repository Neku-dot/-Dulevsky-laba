#include "array.h"

void array_bad_fill(int *arr, int size) {
    int j = 1000;
    for (int i = 0; i < size; i++) {
        arr[i] = j;
        j--;
    }
}

void memory_of_buff(int **arr_for_sort, int **array_copy, int odd_amount) {
    *arr_for_sort = (int *) calloc(odd_amount, sizeof(int));
    *array_copy = (int *) calloc(odd_amount, sizeof(int));
}

void memory(int **arr, int size) {
    *arr = (int *) calloc(size, sizeof(int));
}

void arr_duplicate(const int *array_for_sort, int *array_copy, int last_positive) {
    for (int i = 0; i < last_positive; i++)
        array_copy[i] = array_for_sort[i];
}

void array_fill(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 21 - 10;
    }
}

void array_print(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            printf("\033[1;32m%2d ", array[i]);
        } else
            printf("\033[1;37m%2d ", array[i]);
    }
    printf("\033[1;37m\n");
}

void array_in(const int *array, int *array_for_sort, int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            array_for_sort[j] = array[i];
            j++;
        }
    }
}

void array_move_out(int *array, int *array_for_sort, int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {
            array[i] = array_for_sort[j];
            j++;
        }
    }
}


int find_last_positive(int *array, int size) {
    int last_positive;
    for (int i = size; i > 0; i--) {
        if (array[i] > 0) {
            last_positive = i;
            return last_positive;
        }
    }
}

int counter_of_odd(int *array, int last_positive) {
    int odd_amount=0;
    for (int i = 0; i < last_positive+1; i++) {
        if (array[i] % 2 != 0) {
            odd_amount += 1;
        }
    }
    printf("odd-amnt = %d\n", odd_amount);
    return odd_amount;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *array, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        if (array[i] < 0) {
            for (j = 0; j < size - i - 1; j++)
                if (array[j] > array[j + 1])
                    swap(&array[j], &array[j + 1]);
        }
    }
}

void shell_sort(int *array, int size) {
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

void sorts_time_count(int *array_for_sort, int *array_copy, int last_positive, double *time_for_shell, double *time_spent_bubble) {
    clock_t start = clock();
    shell_sort(array_for_sort, last_positive);
    clock_t end = clock();
    *time_for_shell += (double) (end - start) / CLOCKS_PER_SEC;
    clock_t start_b = clock();
    bubble_sort(array_copy, last_positive);
    clock_t end_b = clock();
    *time_spent_bubble += (double) (end_b - start_b) / CLOCKS_PER_SEC;
}


void choice(int *array, int size) {
    int x;
    printf("How you want to sort an array?\nRandom values (1)\nFrom 0 to -n(2)\n");
    while (scanf_s("%d", &x) != 1 || getchar() != '\n' || x < 1 || x > 2) {
        printf("Error!");
        rewind(stdin);
    }
    if (x == 1)
        array_fill(array, size);
    else if (x == 2)
        array_bad_fill(array, size);
}
