#include "monty.h"

/**
 * _pint - prints the value at the top of the stack.
 * @head: linked list'head address.
 * @line_number: line number of line we're reading.
 * Return: nothing
 */

void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		dprintf(
			STDERR_FILENO,
			"L%d: can't pint, stack empty\n",
			line_number
			);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
