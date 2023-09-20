#include "monty.h"
/**
 * push_fun - pushes an integer to the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void push_fun(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");
	stack_t *new;

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
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	(*stack) = new;
}

/**
 * pall_fun - pushes an integer to the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void pall_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint_fun - print value at the top of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return value
 */

void pint_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		errno = -999;
	}
	else
	{
		printf("%d\n", current->n);
	}
}

/**
 * pop_fun - remove top element of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return value
 */
void pop_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		errno = -999;
	}
	else
	{
		/*printf("%d", top->n);*/

		if ((*stack)->next != NULL)
		{
			(*stack)->next->prev = NULL;
		}
		(*stack) = (*stack)->next;
		free(current);
	}
}

/**
 * swap_fun - remove top element of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return value
 */

void swap_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		errno = -999;
	}
	else
	{
		current = (*stack)->next;
		(*stack)->prev = current;
		(*stack)->next = current->next;
		current->prev = NULL;
		current->next = *stack;
		*stack = current;
	}
}
