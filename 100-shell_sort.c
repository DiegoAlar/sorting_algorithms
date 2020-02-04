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

	while (array != NULL && size > 1 && count < size)
	{
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
		}
		count++;
	}
}


/**
  * shell_sort - sorts an array of integers using knuth sequence
  * @array: the array to be sorted
  * @size: the size of the array
  */
void shell_sort(int *array, size_t size)
{
	int cont2, cont3, tmp, k = 0, cont = 0, flag = 1;

	if (array == NULL || size < 2)
		return;
	while (k * 3 + 1 < (int)size)
	{
		k = k * 3 + 1;
	}
	while ((cont + k) < (int)size)
	{
		cont2 = cont;
		while ((cont2 + k) < (int)size)
		{
			if (array[cont2] > array[cont2 + k])
			{
				tmp = array[cont2];
				array[cont2] = array[cont2 + k];
				array[cont2 + k] = tmp;
				cont3 = cont2;
				flag = 1;
				while ((cont3 - k) > -1 && flag)
				{
					if (array[cont3 - k] > array[cont3])
					{
						tmp = array[cont3];
						array[cont3] = array[cont3 - k];
						array[cont3 - k] = tmp;
						print_array(array, size);
					}
					else
						flag = 0;
					cont3 -= k;
				}
			}
			cont2 += k;
		}
		cont++;
	}
	selection_sort(array, size);
	print_array(array, size);
}
