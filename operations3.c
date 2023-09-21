#include "monty.h"

/**
 * mod_fun - modulo of the top two elements of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void mod_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int first = 0;

	if (stack == NULL || *stack == NULL || stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		errno = -999;
		return;
	}
	curr = *stack;
	first = curr->n;
	curr = curr->next;
	if (first == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		errno = -999;
		return;
	}
	curr->n = curr->n % first;
	del_at_indx(stack, 0);
}

/**
 * pchar_fun - prints char at top of stack using n as ascii code
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void pchar_fun(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		errno = -999;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		errno = -999;
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr_fun - prints stack as string
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void pstr_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	curr = *stack;

	while (curr)
	{
		if (curr->n > 0 && curr->n <= 127)
		{
			printf("%c", curr->n);
		}
		else
		{
			printf("\n");
			return;
		}
		curr = curr->next;
	}
	printf("\n");
}

/**
 * rotl_fun - moves the second top to top and top to last
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void rotl_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *init_stack, *curr;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	init_stack = *stack;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = init_stack;
	init_stack->prev = curr;
	init_stack->next = NULL;
}

/**
 * rotr_fun - rotates to the bottom (last becomes first)
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void rotr_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->prev->next = NULL;
	curr->prev = NULL;
	(*stack)->prev = curr;
	curr->next = *stack;
	*stack = curr;
}
