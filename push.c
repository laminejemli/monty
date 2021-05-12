#include "monty.h"

/**
 * push - push new node to linked list.
 * @line_number: the line number of the monty file that we're currently reading
 * @arg: the push's corresponding arg.
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *element = NULL;
	int num = atoi(arg);
	(void)line_number;

	free(arg);
	element = malloc(sizeof(*element));
	if(element == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	element->n = num;
	if (*stack == NULL)
	{
		element->prev = NULL;
		element->next = NULL;
		*stack = element;
	}
	else
	{
		(*stack)->prev = element;
		element->next = *stack;
		element->prev = NULL;
		*stack = element;
	}
}
