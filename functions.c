#include "functions.h"

int* create_array(int count, int limit)
{
    int* array = NULL;
    array = (int*)malloc(count * sizeof(int));

    if(array == NULL)
    {
        fprintf(stderr,RED_COLOR "\nMEMORY ERROR in create_array(int count)\n" RESET_COLOR);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < count; i++)
    {
        array[i] = rand() % limit;
    }
    return array;
}


void print_array(int* array, int count)
{
    if(array == NULL)
        return;

    for(int i=0; i < count; i++)
    {
        printf("\narr[%d] = %d", i, array[i]);
    }
    printf("\n");
}

