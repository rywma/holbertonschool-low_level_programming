#include "lists.h"

/**
 * get_dnodeint_at_index - returns the n node of a linked list
 * @head: pointer to the head of the list
 * @index: index of the node to find (starting from 0)
 *
 * Return: the address of the node or NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
