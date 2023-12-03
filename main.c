#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include "time.h"
#include "functions.h"

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

#define SIZE 10
#define LIMIT 15
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
        fprintf(stderr,RED_COLOR "OpenMP not suppoted\n\n" RESET_COLOR);
        exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
    check_openmp_support();

    srand(time(NULL));
    int* array = create_array(SIZE, LIMIT);
    print_array(array, SIZE);
    

    //shell_sort();
    
    free(array);

    return 0;
}