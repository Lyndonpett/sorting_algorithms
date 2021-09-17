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
		return;
	/* set our lists to the actual list */
	current = (*list)->next;
	tmp = current;

	while (current != NULL)
	{ /* set current to current next */
		current = current->next;
		/* checks if not at the head and the value of n is greater than prev value*/
		if (tmp->n < tmp->prev->n)
		{ /* as long as we are in the right place, keep looping */
			while (tmp->prev != NULL && tmp->n < tmp->prev->n)
			{ /* set our destination */
				finalNode = tmp->prev;
				finalNode->next = tmp->next;
				/* keep going till null previous */
				if (finalNode->prev != NULL)
					finalNode->prev->next = tmp;
				/* keep going till null next */
				if (tmp->next != NULL)
					tmp->next->prev = finalNode;
				/* set all tmp values to our final node */
				tmp->prev = finalNode->prev;
				tmp->next = finalNode;
				finalNode->prev = tmp;
				/* if we are where we need to be, set our list equal to tmp */
				if (tmp->prev == NULL)
				{
					(*list) = tmp;
				}
				/* print list */
				print_list(*list);
			}
		}
		tmp = current;
	}
}
