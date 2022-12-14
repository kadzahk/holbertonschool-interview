#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a new number as a node into sorted list
 * @head: pointer to the head of the sorted singly linked list
 * @number: number to sort and add into list as new node
 * Return: pointer to the new node, or NULL if error encountered
 */

 listint_t *insert_node(listint_t **head, int number)
 {
	listint_t *new = NULL, *tempo = NULL;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	tempo = *head;
	if (tempo->n > number)
	{
		*head = new;
		new->next = tempo;
		return (new);
	}
	while (tempo->next != NULL && tempo->next->n <= number)
		tempo = tempo->next;
	new->next = tempo->next;
	tempo->next = new;
	return (new);
}