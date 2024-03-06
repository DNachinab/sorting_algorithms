#include "sort.h"

/**
 * swap_ints - Swapping two integers in an array.
 * @x: First integer to swap.
 * @y: Second integer to swap.
 */

void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Using shell sort algorithm
 * 				to sort an array in ascending order.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				swap_ints(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
