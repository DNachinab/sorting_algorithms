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
 * hoare_part - Arrange sub-array of integers according
 * 				to the hoare partition scheme.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_part(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_s - Using the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_s(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_part(array, size, left, right);
		hoare_s(array, size, left, part - 1);
		hoare_s(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Using the quicksort algorithm to sort
 * 					an array of integers in ascending order.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_s(array, size, 0, size - 1);
}
