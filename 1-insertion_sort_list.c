#include "sort.h"

/**
 * insertion_sort_list - insert sorts a list
 *
 * @list: the list.
 *
 * Return: void.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *tmp = NULL, *finalNode = NULL;

	if (list == NULL)
	{
		return;
	}
	current = (*list)->next;
	tmp = current;

	while (current != NULL)
	{
		current = current->next;

		if (tmp->n < tmp->prev->n)
		{
			while (tmp->prev != NULL && tmp->n < tmp->prev->n)
			{
				finalNode = tmp->prev;
				finalNode->next = tmp->next;
				if (finalNode->prev != NULL)
				{
					finalNode->prev->next = tmp;
				}
				if (tmp->next != NULL)
				{
					tmp->next->prev = finalNode;
				}
				tmp->prev = finalNode->prev;
				tmp->next = finalNode;
				finalNode->prev = tmp;
				if (tmp->prev == NULL)
				{
					(*list) = tmp;
				}
				print_list(*list);
			}
		}
		tmp = current;
	}
}
