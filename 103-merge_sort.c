#include "sort.h"

/**
 * merge_sbarr - Sort a sub-array of integers.
 * @subarr: Sub-array of an array of integers to sort.
 * @buff: A buffer to store the sorted sub-array.
 * @front: Front index of the array.
 * @mid: Middle index of the array.
 * @back: Back index of the array.
 */
void merge_sbarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; c++)
		buff[c] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[c++] = subarr[a];
	for (; b < back; b++)
		buff[c++] = subarr[b];
	for (a = front, c = 0; a < back; a++)
		subarr[a] = buff[c++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recur - Merge sort algorithm through recursion.
 * @subarr: Sub-array of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: Front index of the sub-array.
 * @back: Back index of the sub-array.
 */
void merge_sort_recur(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recur(subarr, buff, front, mid);
		merge_sort_recur(subarr, buff, mid, back);
		merge_sbarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - using the merge sort algorithm to
 * 				sort an array of integers in ascending
 *              order.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recur(array, buff, 0, size);

	free(buff);
}
