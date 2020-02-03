#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ...
 * @array: is my vector
 * @size: is the len of my array
 */

void selection_sort(int *array, size_t size)
{
size_t i, idx, count = 0;
int aux, flag = 1;
	do {
		flag = 0;
		aux = array[count];
		for (i = count + 1; i < size; i++)
		{
			if (array[i] < aux)
			{
				aux = array[i];
				idx = i;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			array[idx] = array[count];
			array[count] = aux;
			print_array(array, size);
		}
		count++;
	} while (count < size);
}
