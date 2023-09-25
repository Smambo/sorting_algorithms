#include "sort.h"

/**
 * swap - swaps nodes in the list
 * @pre: previous (first) node
 * @current: current (second) node
 * @list: list with nodes to be swapped
 * Return: nothing
 */
void swap(listint_t *pre, listint_t *current, listint_t **list)
{
	if (!(pre->prev))
	{
		pre->next = current->next;
		if (current->next)
			current->next->prev = pre;
		current->next = pre;
		current->prev = NULL;
		pre->prev = current;
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
}

/**
 * cocktail_sort_list - sorts a doubly linked list of ints in
 *            ascending order using Cocktail shaker sort algo
 * @list: list to be sorted
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *next_node;
	int swop;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;
	current = (*list);
	do {
		swop = 0;
		while (current->next)
		{
			next_node = current->next;
			if (next_node && current->n > next_node->n)
			{
				swap(current, next_node, list);
				swop = 1;
				print_list((*list));
			}
			else
				current = current->next;
		}
		current = current->prev;
		while (current->prev)
		{
			next_node = current->prev;
			if (next_node && current->n < next_node->n)
			{
				swap(next_node, current, list);
				swop = 1;
				print_list((*list));
			}
			else
				current = current->prev;
		}
		current = current->next;
	} while (swop);
}
