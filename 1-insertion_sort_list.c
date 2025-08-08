#include "sort.h"
/**
* swap_nodes - a function that swaps two nodes in a doubly linked list
* @a: the first node
* @b: the second node
* @list: a pointer to the head of the list
*/
void swap_nodes(listint_t *a, listint_t *b, listint_t **list)
{
	listint_t *tmp_prv, *tmp_nxt;

	tmp_prv = (*a).prev;
	tmp_nxt = (*b).next;

	if (tmp_prv != NULL)
		tmp_prv->next = b;
	else
		*list = b;

	if (tmp_nxt != NULL)
		tmp_nxt->prev = a;

	(*a).prev = b;
	(*a).next = tmp_nxt;
	(*b).prev = tmp_prv;
	(*b).next = a;
}

/**
* insertion_sort_list - a function that sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm.
* @list: a pointer to the pointer to the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *actual, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	actual = (*list)->next;
	while (actual != NULL)
	{
		swap = actual;
		while ((*swap).prev != NULL && (*swap).n < (*swap).prev->n)
		{
			swap_nodes((*swap).prev, swap, list);
			print_list(*list);
		}
		actual = (*actual).next;
	}
}
