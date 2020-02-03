#include "sort.h"
/**
  * partition - finds out pivot
  * @array: array to be sorted
  * @lo: the minumum index in the array
  * @hi: max number index in the list
  * Return: the pivot
  */
int partition(int *array, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo;
	int temp = 0;

	for (int j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			i++;
		}
	}
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;
	return (i);
}


/**
  * quicksort - quick sort algorithm
  * @array: the array to be sorted
  * @lo: the minimum index of list
  * @hi: the maximum index in the range of the list
  */
void quicksort(int *array, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi);
		quicksort(array, lo, p - 1);
		quicksort(array, p + 1, hi);
	}

}

/**
  * quick_sort - quick sort algorithm
  * @array: the array to be sorted
  * @size: the size of the array
  */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size);

}
