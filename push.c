#include "monty.h"

/**
 * push - push new node to linked list.
 * @line_number: the line number of the monty file that we're currently reading
 * @arg: the push's corresponding arg.
 * Return: nothing.
 */
void _push(stack_t **stack, unsigned int line_number, char *arg)
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
/**
 * check_push_arg - check if a push command has an arg in its line.
 * @token: token corresponding the push's line.
 * Return: pointer to character representing the push's arg or NULL.
 */
char *check_push_arg(char *token)
{
	char *token2;
	char *arg;
	int i, len;

	(void)token;

	token2 = strtok(NULL, " \n");

	while (token2 && token2[0] == ' ')
		token2 = strtok(NULL, " \n");

	if (!token2)
		get_usage_err();
	for (len = 0;
	     (token2[len] && token2[len] != '\n' && token2[len] != ' ');
	     len++)
		;

	arg = malloc(sizeof(char) * (len + 1));

	if (!arg)
		get_usage_err();

	for (i = 0; i < len; i++)
		arg[i] = token2[i];
	arg[i] = '\0';

	is_number(arg);

	return (arg);
}

/**
 * get_usage_err - displays usage error.
 */
void get_usage_err(void)
{
	dprintf(
		STDERR_FILENO,
		"L%d: usage: push integer\n",
		line_number);
	exit(EXIT_FAILURE);
}

/**
 * is_number - check if the push argument is a number of not
 * @str: the token that's retrieved after a found 'push' command.
 * in a given line.
 */
void is_number(char *str)
{
	int i = 0;

	if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '-')
		get_usage_err();
	else
		i++;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			get_usage_err();
	}
}
