#include "sort.h"
/**
  * partition - finds out pivot
  * @array: array to be sorted
  * @lo: the minumum index in the array
  * @hi: max number index in the list
  * @size: size of the array
  * Return: the pivot
  */
int partition(int *array, int lo, int hi, int size)
{
	int pivot = array[hi];
	int i = lo, j = lo;
	int temp = 0;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;
	if (array[i] != array[hi])
		print_array(array, size);
	return (i);
}


/**
  * quicksort - quick sort algorithm
  * @array: the array to be sorted
  * @lo: the minimum index of list
  * @hi: the maximum index in the range of the list
  * @size: size of the array
  */
void quicksort(int *array, int lo, int hi, int size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}

}

/**
  * quick_sort - quick sort algorithm
  * @array: the array to be sorted
  * @size: the size of the array
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, (int)size - 1, (int)size);
}
