#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

int choice(int n);

int menu(int n);

void delete_element(int** array, int* size, int index);

void fill_array_task1(int* array, int size);

void memory_task1(int** array, int size);

void print_array_task1(int* array, int size);

void multiple11_task1(int** array, int* size);

void print_array(int* x, int* y);

void rand_elem(int* arr, int razmer);

void elem_write(int element, int razmer, int* arr);

void dimension(int* x);

void task_1();

//TASK 2
void memory_one_element_task2(int** array, int sizeofrows);

void input_array_task2(int** array, int sizeofrows);

int array_size_input_task2(int arraysize);

void print_array(int** array, int sizeofrows);

void delete_zoro(int sizeofrows, int** array);

void Task_2();

int* rem_element(int* arr, int pos, int razmer);

void print_low(int row, int** arr);

int** search_max(int** arr, int razmer, int low, int num);

int* write_num(int number, int* razmer);

void task_2();

//TASK 3
void rand_array_task3(int*** array, int col, int row);

void print_array_task3(int** array, int row, int col);

int size_input_check_task3(int n);

int amount_task3(int row, int col);

void check_element_task3(int** array, int row, int col);

void free_array(int** array, int row);

void delete_row(int*** array, int* row, int col, int l);

void task_3();