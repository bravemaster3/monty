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
