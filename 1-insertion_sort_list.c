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
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: the list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list;
	listint_t *tmp2 = NULL;
	int flag = 1;

	while (list && *list && tmp->next)
	{
		flag = 1;
		if (tmp->n > tmp->next->n)
		{
			tmp = swap_func(&tmp);
				if (tmp->prev == NULL)
					*list = tmp;
			print_list(*list);
			tmp2 = tmp;
		}
		while (tmp2 && tmp2->prev && flag)
		{
			if (tmp2->prev->n > tmp2->n)
			{
				tmp2 = tmp2->prev;
				tmp2 = swap_func(&tmp2);
				if (tmp2->prev == NULL)
					*list = tmp2;
				print_list(*list);
			}
			else
			{
				flag = 0;
			}
		}
		tmp2 = NULL;
		tmp = tmp->next;
	}
}
