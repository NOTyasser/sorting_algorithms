#include "sort.h"

/**
 * insertion_sort_list - sort the array
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (!list || !*list || !(*list)->next)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		while (prev != NULL && prev->n > curr->n)
		{
			if (prev->prev)
				prev->prev->next = curr;
			if (curr->next)
				curr->next->prev = prev;
			prev->next = curr->next;
			curr->prev = prev->prev;
			prev->prev = curr;
			curr->next = prev;

			prev = curr->prev;
			if (prev == NULL)
				*list = curr;
			print_list(*list);
		}
		curr = curr->next;
	}
}
