#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern unsigned int line_number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _push(stack_t **stack, unsigned int line_number, char *arg);

char *check_push_arg(char *token);
void _pall(stack_t **head, unsigned int line_number);
void treat_line(stack_t **head, char *line);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void free_dlistint(stack_t *head);

void treat_token(stack_t **head, char *token);
void (*get_function(char *token))(stack_t **, unsigned int);
void get_invalid_opcode(char *token);
void _sub(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);

void is_number(char *str);

void get_usage_err(void);
#endif
