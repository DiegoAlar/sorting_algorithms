#include "sort.h"
/**
  * bubble_sort - sorts array of int in ascending order using Bubble sort
  * @array: the array to be sorted
  * @size: the size of the array
  */
void bubble_sort(int *array, size_t size)
{
	unsigned long int cont = 0;
	int temp = 0;
	unsigned long int k;
	int flag = 1;

	while (flag && size != 0)
	{
		flag = 0;
		for (k = 1; k < (size - cont); k++)
		{
			if (array[k - 1] > array[k])
			{
				flag = 1;
				temp = array[k - 1];
				array[k - 1] = array[k];
				array[k] = temp;
				print_array(array, size);
			}
		}
		cont++;
	}
}
