#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include "time.h"

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

int* create_array(int count, int limit);
void print_array(int* array, int count);