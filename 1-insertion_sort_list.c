#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of ints
 *                in ascending order using insertion algo
 * @list: doubly linked list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *pre, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	temp = current->next;
	while (current)
	{
		if (current->n < current->prev->n)
		{
			pre = current->prev;
			while (pre && (current->n < pre->n))
			{
				if (!(pre->prev))
				{
					pre->prev = current;
					current->prev->next = current->next;
					if (current->next)
						current->next->prev = current->prev;
					current->next = pre;
					current->prev = NULL;
					*list = current;
				} else
				{
					current->prev->next = current->next;
					if (current->next)
						current->next->prev = current->prev;
					pre->prev->next = current;
					current->prev = pre->prev;
					pre->prev = current;
					current->next = pre;
				}
				print_list(*list);
				pre = current->prev;
			}
		}
		current = temp;
		current ? (temp = current->next) : (temp = NULL);
	}
}
