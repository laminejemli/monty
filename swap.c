#include "monty.h"

/**
 * _swap - swap the top two elements of the stack.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int line_number)
{
	int n;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(
			STDERR_FILENO,
			"L%d: can't swap, stack too short\n",
			line_number
			);
		if (*head != NULL)
		{
			free_dlistint(*head);
		}
		exit(EXIT_FAILURE);
	}

	n = (*head)->n;
	(*head)->n = ((*head)->prev)->n;
	((*head)->prev)->n = n;
}
/**
 * free_dlistint - free doubly linked lists
 * @head: head of linked lists
 **/
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->prev;
		free(temp);
	}
	free(head);
}
