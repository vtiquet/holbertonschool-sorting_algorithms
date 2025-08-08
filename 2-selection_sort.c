#include "sort.h"
/**
 * selection_sort -  a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: the array to be sorted.
 * @size: the number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i1 = 0, i2 = 0, min_i = 0;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (i1 < size - 1)
	{
		min_i = i1;
		for (i2 = i1 + 1; i2 < size; i2++)
		{
			if (array[i2] < array[min_i])
			{
				min_i = i2;
			}
		}
		if (min_i != i1)
		{
			tmp = array[i1];
			array[i1] = array[min_i];
			array[min_i] = tmp;
			print_array(array, size);
		}
		i1++;
	}
}
