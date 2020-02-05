#include "sort.h"
/**
 * swap_func - function to swapear
 * @head: our doubly linked list
 * Return: The node in the correct place
 */
listint_t *swap_func(listint_t **head)
{
listint_t *tmp = (*head)->next;
	if (tmp->next)
		tmp->next->prev = *head;
	if ((*head)->prev)
		(*head)->prev->next = tmp;
	(*head)->next = tmp->next;
	tmp->prev = (*head)->prev;
	(*head)->prev = tmp;
	tmp->next = *head;
	return (tmp);
}
/**
 * cocktail_sort_list - sorted
 * @list: My double linked list
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tmp = NULL;
int cont2 = 1024, cont, contlist = 0, i, j;
	if (!list)
		return;
	tmp = *list;
	while (cont2 > 0)
	{
		cont = 1, i = 1, j = 1;
		while (tmp->next && i <= (cont2 - 1))
		{
			cont++;
			if (contlist > 0)
				i++;
			if (tmp->n > tmp->next->n)
			{
				tmp = swap_func(&tmp);
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
			tmp = tmp->next;
		}
		tmp = tmp->prev;
		while (tmp->prev && j <= (cont - 1))
		{
			j++;
			if (tmp->n < tmp->prev->n)
			{
				tmp = tmp->prev;
				tmp = swap_func(&tmp);
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
		tmp = tmp->next;
		cont2 = cont - 1, contlist++;
	}
}
