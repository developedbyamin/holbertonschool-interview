#include "search_algos.h"

/**
 * find_index - Finds the index of the first occurrence of a value in an array.
 * @array:    (int*)  Sorted array of integers.
 * @start:    (size_t) Index indicating the start of the sub-array.
 * @end:      (size_t) Index indicating the end of the sub-array.
 * @value:    (int)   Value to be found.
 * 
 * Return:    (int)   Index where the value is located or -1 if not found.
 */
int find_index(int *array, size_t start, size_t end, int value)
{
    size_t mid;

    if (start >= end)
        return (-1);

    printf("Searching in array: ");
    for (size_t i = start; i < end; i++)
    {
        printf("%d", array[i]);
        if (i < end - 1)
            printf(", ");
    }
    printf("\n");

    mid = (start + end) / 2;

    if (array[mid] == value)
    {
        // Check if it's the first occurrence
        if (mid == start || array[mid - 1] < value)
            return mid;
        // Continue searching in the left half
        return find_index(array, start, mid, value);
    }
    else if (array[mid] < value)
    {
        return find_index(array, mid + 1, end, value);
    }
    else
    {
        return find_index(array, start, mid, value);
    }
}

/**
 * advanced_binary - Finds an item and its position in a sorted array.
 * @array:   (int*)   Array of elements.
 * @size:    (size_t) Length of the array.
 * @value:   (int)    Value to be located in the array.
 * 
 * Return:   (int)    Index position if found or -1 otherwise.
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size < 1)
        return (-1);
    
    return find_index(array, 0, size, value);
}

