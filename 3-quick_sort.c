#include "sort.h"
/**
* swap_elements - a function that swaps two integer elements in an array.
* @a: a pointer to the first element.
* @b: a pointer to the second element.
*/
void swap_elements(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
* lomuto_partition - a function that partitions
* an array using the Lomuto scheme.
* @array: the array to be partitioned.
* @start: the starting index of the partition.
* @end: the ending index of the partition (pivot).
* @size: the total size of the array for printing.
* Return: the final index of the pivot element.
*/
int lomuto_partition(int *array, int start, int end, size_t size)
{
    int p = array[end];
    int i1 = start - 1, i2 = start;

    while (i2 <= end - 1)
    {
        if (array[i2] <= p)
        {
            i1++;
            if (i1 != i2)
            {
                swap_elements(&array[i1], &array[i2]);
                print_array(array, size);
            }
        }
        i2++;
    }
    if (array[i1 + 1] > array[end])
    {
        swap_elements(&array[i1 + 1], &array[end]);
        print_array(array, size);
    }
    return (i1 + 1);
}

/**
* quick_sort_recursive - a recursive function that sorts an array of integers
* in ascending order using the Quick sort algorithm.
* @array: the array to be partitioned.
* @start: the starting index of the partition.
* @end: the ending index of the partition (pivot).
* @size: the total size of the array for printing.
*/
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
    int p_i;

    if (start < end)
    {
        p_i = lomuto_partition(array, start, end, size);
        quick_sort_recursive(array, start, p_i - 1, size);
        quick_sort_recursive(array, p_i + 1, end, size);
    }
}

/**
* quick_sort - a function that sorts an array of integers
* in ascending order using the Quick sort algorithm
* @array: The array to be sorted.
* @size: The number of elements in the array.
*/
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_recursive(array, 0, size - 1, size);
}
