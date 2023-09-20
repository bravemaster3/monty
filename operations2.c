#include "monty.h"

/**
 * add_fun - adds the top two elements of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void add_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int first = 0;

	if (stack == NULL || *stack == NULL || stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		errno = -999;
		return;
	}
	curr = *stack;
	first = curr->n;
	curr = curr->next;
	curr->n = curr->n + first;
	del_at_indx(stack, 0);
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

/**
 * sub_fun - subs the top two elements of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void sub_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int first = 0;

	if (stack == NULL || *stack == NULL || stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		errno = -999;
		return;
	}
	curr = *stack;
	first = curr->n;
	curr = curr->next;
	curr->n = curr->n - first;
	del_at_indx(stack, 0);
}

/**
 * div_fun - divides the top two elements of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void div_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int first = 0;

	if (stack == NULL || *stack == NULL || stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	curr->n = curr->n / first;
	del_at_indx(stack, 0);
}

/**
 * mul_fun - multiplies the top two elements of the stack
 * @stack: pointer to top (pointer to pointer)
 * @line_number: liner number in the file
 * Return: No return
 */
void mul_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int first = 0;

	if (stack == NULL || *stack == NULL || stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		errno = -999;
		return;
	}
	curr = *stack;
	first = curr->n;
	curr = curr->next;
	curr->n = curr->n * first;
	del_at_indx(stack, 0);
}
