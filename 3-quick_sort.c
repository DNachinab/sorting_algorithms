#include "sort.h"

void swap_ints(int *x, int *y);
int lom_part(int *array, size_t size, int left, int right);
void lom_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lom_part - Using the lomuto partition strategy
 * 					to sort a subset of a numeric array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lom_part(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lom_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lom_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lom_part(array, size, left, right);
		lom_sort(array, size, left, part - 1);
		lom_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Using the quicksort method
 * 				to arrange an arrays in ascending order.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lom_sort(array, size, 0, size - 1);
}
