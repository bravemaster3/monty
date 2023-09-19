#include "monty.h"
/**
 * push_fun - pushes an integer to the stack
 * @n: the integer to be pushed
 * Return: No return
 */
void push_fun(int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	new->n = n;
	new->next = top;
	new->prev = NULL;
	if (top != NULL)
		top->prev = new;
	top = new;
}

/**
 * pall_fun - prints all integers of the stack
 * Return: No return
 */
void pall_fun()
{
	stack_t *current = top;

	if (top != NULL)
	{
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
