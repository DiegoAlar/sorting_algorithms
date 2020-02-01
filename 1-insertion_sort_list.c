#include "sort.h"


/**
 * swap_func - function to swapear
 * @head: our doubly linked list
 * Return: The node in the correct place
 */
listint_t* swap_func(listint_t **head)
{
	listint_t *tmp = (*head)->next;

	tmp->next->prev = *head;
	(*head)->prev->next = tmp;
	tmp->next = *head;
	tmp->prev = (*head)->prev;
	tmp->next = *head;
	(*head)->next = (*head)->next->next;
	(*head)->prev = tmp;

	return(tmp);
}


/**
 * 
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list;
	listint_t *tmp2 = NULL;
	int flag = 1;
	while (tmp && flag)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp = swap_func(&tmp);
			tmp2 = tmp;
		}
		while (tmp2 && tmp2->prev && flag)
		{
			if (tmp2->prev->n > tmp2->n)
				tmp2 = swap_func(&tmp2);
			else
				flag = 0;
		}
		tmp = tmp->next;
	}	
}

