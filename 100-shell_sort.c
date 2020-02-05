#include "sort.h"

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
	while (k * 3 + 1 <= (int)size)
		k = k * 3 + 1;
	while (k > 0)
	{
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
		print_array(array, size);
		k = (k - 1) / 3;
	}
}

