#include "array.h"

int main() 
{
    srand(time(0));
    int* array, * arr_for_sort, * array_copy, size, last_positive=0, odd_amount=0;
    double time_for_shell = 0.0, time_spent_bubble = 0.0;
    printf("Input size of array:");
    scanf_s("%d", &size);
    memory(&array, size);
    choice(array, size);
    last_positive = find_last_positive(array, size);
    odd_amount = counter_of_odd(array, last_positive);
    printf("Original arr:\n");
    array_print(array, size);
    memory_of_buff(&arr_for_sort, &array_copy, odd_amount);
    array_in(array, arr_for_sort, size);
    arr_duplicate(arr_for_sort, array_copy, odd_amount);
    sorts_time_count(arr_for_sort, array_copy, odd_amount, &time_for_shell, &time_spent_bubble);
    array_move_out(array, arr_for_sort, size);
    printf("Sorted array:\n");
    array_print(array, size);
    printf("\nTime spent for shell sort = %f", time_for_shell);
    printf("\nTime spent for bubble sort = %f", time_spent_bubble);
    free(array);
    return 0;
}