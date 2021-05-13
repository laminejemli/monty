#include "monty.h"

/**
 * treat_line - function that gets the line from monty file
 * @head: linked list head address
 * @line: line we're treating from the monty file
 * Return: nothing
 */
void treat_line(stack_t **head, char *line)
{
	char *token = NULL;

	token = strtok(line, " \n");
	while (token && token[0] == ' ')
		token = strtok(NULL, " \n");
	if (!token)
		return;
	treat_token(head, token);
}
