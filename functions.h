#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include "time.h"

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"


int* create_array(int size, int limit);
void print_array(int* array, int size);
void copy_array(int* src, int** dst, int size);

void shell_sort(int* array, int size);
void shell_sort_parallel(int* array, int size, int threads);