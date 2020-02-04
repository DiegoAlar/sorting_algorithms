#include "sort.h"

/**
  * shell_sort - sorts an array of integers using knuth sequence
  * @array: the array to be sorted
  * @size: the size of the array
  */
void shell_sort(int *array, size_t size)
{
	int j, i, tmp, k = 0;

	if (array == NULL || size < 2)
		return;
	while (k * 3 + 1 <= (int)size)
	{
		k = k * 3 + 1;
	}
	while (k > 0)
	{
		for (i = k; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; j >= k && array[j - k] > tmp; j -= k)
				array[j] = array[j - k];
			array[j] = tmp;
		}
		print_array(array, size);
		k = (k - 1) / 3;
	}
}
