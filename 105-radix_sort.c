#include "sort.h"

int get_max(int *array, int size);

/**
 * get_max - Get the max value in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, a;

	for (max = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}

	return (max);
}

/**
 * radix_count_sort - Using the counting sort algorithm in ascending
 * order to sort the significant digits of an array of integers
 *
 * @array: Array of integers.
 * @size: Size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
		count[(array[a] / sig) % 10] += 1;

	for (a = 0; a < 10; a++)
		count[a] += count[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		buff[count[(array[a] / sig) % 10] - 1] = array[a];
		count[(array[a] / sig) % 10] -= 1;
	}

	for (a = 0; a < size; a++)
		array[a] = buff[a];
}

/**
 * radix_sort - Using the radix sort algorithm in ascending
 *              order to sort an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
