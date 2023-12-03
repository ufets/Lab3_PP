#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include "time.h"
#include "functions.h"

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

#define SIZE 1000000
#define LIMIT 10000

/// @brief Different codes of errors
enum CODES
{
    ERROR,
    OK
};

/// @brief Checking does openmp supports
void check_openmp_support()
{
#ifdef _OPENMP
    printf("\n== OpenMP vesion: %d ==\n", _OPENMP);
    return;
#endif
    fprintf(stderr, RED_COLOR "OpenMP not suppoted\n\n" RESET_COLOR);
    exit(EXIT_FAILURE);
}

void timing(int *array, int *array2, int size)
{
    clock_t start1 = clock();
    shell_sort(array, size);
    clock_t end1 = clock();
    printf("result:\t%lf\n", (double)(end1 - start1) / CLOCKS_PER_SEC);

    int num = 100;
    double result = 0;
    for (int i = 1; i <= 12; i++)
    {
        for(int j = 0; j < num; j++)
        {
            double start = omp_get_wtime();
            shell_sort_parallel(array2, SIZE, i);
            double end = omp_get_wtime();
            result += end - start;
        }
        
        printf("%lf\n", result / num);
        result = 0;
    }
}

int main(int argc, char *argv[])
{
    check_openmp_support();

    srand(time(NULL));
    int *array = create_array(SIZE, LIMIT);
    int *array2 = NULL;
    copy_array(array, &array2, SIZE);

    timing(array, array2, SIZE);

    free(array);

    return 0;
}