#include "monty.h"

/**
 * swap_fun - remove top element of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return value
 */

void swap_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || stack_len(*stack) < 2)
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

/**
 * nop_fun - remove top element of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return value
 */

void nop_fun(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
