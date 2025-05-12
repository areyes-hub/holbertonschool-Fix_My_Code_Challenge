#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list.
 * @head: Pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head = *head;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	for (i = 0; *head != NULL && i < index; i++)
		*head = (*head)->next;

	if (*head == NULL)
	{
		*head = saved_head;
		return (-1);
	}

	if ((*head)->prev != NULL)
		(*head)->prev->next = (*head)->next;
	else
		saved_head = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->prev = (*head)->prev;

	free(*head);
	*head = saved_head;
	return (1);
}
