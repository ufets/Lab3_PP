#include "functions.h"

int* create_array(int size, int limit)
{
    int* array = NULL;
    array = (int*)malloc(size * sizeof(int));

    if(array == NULL)
    {
        fprintf(stderr,RED_COLOR "\nMEMORY ERROR in create_array(int count)\n" RESET_COLOR);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % limit;
    }
    return array;
}


void print_array(int* array, int size)
{
    if(array == NULL)
        return;

    for(int i=0; i < size; i++)
    {
        printf("\narr[%d] = %d", i, array[i]);
    }
    printf("\n");
}

void copy_array(int* src, int** dst, int size)
{
    *dst = (int*)malloc(size * 4);

    for(int i = 0; i < size; i++)
    {
        (*dst)[i] = src[i];
    }
}

void shell_sort(int* array, int size)
{
    for(int step = size / 2; step > 0; step /= 2) 
    {
        for(int i = step; i < size; i++) 
        {
            for(int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) 
            {
                int temp = array[j];
                array[j] = array[j + step];
                array[j + step] = temp;
            }
        }
    }
}

void shell_sort_parallel(int* array, int size, int threads)
{
    for(int step = size / 2; step > 0; step /= 2) 
    {
        #pragma omp parallel for shared(array, size, step) num_threads(threads)
        for(int i = step; i < size; i++) 
        {
            for(int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) 
            {
                int temp = array[j];
                array[j] = array[j + step];
                array[j + step] = temp;
            }
        }
    }
}