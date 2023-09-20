#include "monty.h"
/**
 * pint_fun - print value at the top of the stack
 * Return: No return value
 */

void pint_fun()
{
	stack_t *current = top;

	if (current == NULL)
	{
		fprintf(stderr, "Error: stack is empty\n");
	}
	else
	{
		printf("%d\n", current->n);
	}
}

/**
 * pop_fun - remove top element of the stack
 * Return: No return value
 */
void pop_fun()
{
	stack_t *current = top;

	if (top == NULL)
	{
		fprintf(stderr, "Error: empty stack\n");
	}
	else
	{
		/*printf("%d", top->n);*/

		if (top->next != NULL)
		{
			top->next->prev = NULL;
		}
		top = top->next;
		free(current);
	}
}
/**
 * stack_len - count the number of elemet in stack
 *
 * Return: Number of element
 */
int stack_len()
{
	int count = 0;
	stack_t *current = top;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return count;
}
void swap_fun()
{
	stack_t *current;

	current = top->next;

	if (stack_len() < 2)
	{
		fprintf(stderr, "Error: can't swap, stack too short\n");
	}
	else
	{
		top->prev = current;
		top->next = current->next;
		current->prev = NULL;
		current->next = top;
		top = current;
	}
}
