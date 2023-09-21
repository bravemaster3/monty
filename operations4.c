#include "monty.h"

/**
 * push_queue_fun - adds node at the end of a stack, i.e. in queue mode
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void push_queue_fun(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");
	stack_t *new, *ptr;

	if (arg == NULL || is_valid_integer(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		errno = -999;
		return;
	}

	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		errno = -999;
		return;
	}

	new->n = atoi(arg);
	new->next = NULL;

	ptr = *stack;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = new;
	new->prev = ptr;
}

/**
 * queue_fun - Changes mode to queue
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void queue_fun(stack_t **stack, unsigned int line_number)
{
	int i;

	(void)stack;
	(void)line_number;

	for (i = 0; all_ops[i].opcode != NULL; i++)
	{
		if (strcmp("push", all_ops[i].opcode) == 0)
		{
			all_ops[i].f = push_queue_fun;
			break;
		}
	}
}

/**
 * stack_fun - Changes mode to stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void stack_fun(stack_t **stack, unsigned int line_number)
{
	int i;

	(void)stack;
	(void)line_number;

	for (i = 0; all_ops[i].opcode != NULL; i++)
	{
		if (strcmp("push", all_ops[i].opcode) == 0)
		{
			all_ops[i].f = push_fun;
			break;
		}
	}
}
