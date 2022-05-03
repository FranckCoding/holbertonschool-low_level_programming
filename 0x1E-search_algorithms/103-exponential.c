#include "search_algos.h"

/**
 * binary_search_recursion - Do the binary search in recursion
 *
 * @array: pointer to the first element of the array to search in
 * @min: The index min where we are
 * @max: The index max where we are
 * @value: the value to search for
 * Return: If value is not present in array or if array is NULL, return -1
 * Otherwise, return the first index of value
 */
int binary_search_recursion(int *array, size_t min, size_t max, int value)
{
	size_t index = (max + min) / 2;
	size_t loop;

	printf("Searching in array: ");
	for (loop = min; loop <= max; loop++)
	{
		printf("%d", array[loop]);
		if (loop < max)
			printf(", ");
		else
			printf("\n");
	}

	if (min == max)
	{
		if (value == array[max])
			return (max);
		else
			return (-1);
	}

	if (value == array[index])
		return (index);

	if (value < array[index])
		return (binary_search_recursion(array, min, index - 1, value));

	if (value > array[index])
		return (binary_search_recursion(array, index + 1, max, value));

	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 *
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 * Return: If value is not present in array or if array is NULL, return -1
 * Otherwise, return the first index of value
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t search, prev;

	if (array == NULL)
		return (-1);

	search = 1;

	while (search < size && array[search] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", search, array[search]);
		search *= 2;
	}

	prev = search / 2;

	if (search >= size)
		search = size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", prev, search);

	return (binary_search_recursion(array, prev, search, value));
}
