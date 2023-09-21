#include "monty.h"

/**
 * is_valid_integer - checks if a string is a valid int
 * @str: the pointer to the string
 * Return: 1 if an integer, 0 otherwise
 */
int is_valid_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * free_stack - frees stack before exiting
 * @top: pointer to the top of the stack
 */
void free_stack(stack_t *top)
{
	stack_t *ptr, *tmp;

	if (top != NULL)
	{
		ptr = top;
		while (ptr)
		{
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
	}
}

/**
 * stack_len - counts number of elements in stack
 * @top: pointer to the top of the stack
 * Return: the length
 */
int stack_len(stack_t *top)
{
	int len = 0;
	stack_t *curr = top;

	if (top == NULL)
		return (0);

	while (curr != NULL)
	{
		len++;
		curr = curr->next;
	}

	return (len);
}

/**
 * del_at_indx - deletes a node at index
 * @top: pointer to the head pointer
 * @index: index where the node should be removed
 * Return: 1 on success, -1 otherwise
 */
int del_at_indx(stack_t **top, unsigned int index)
{
	stack_t *ptr;
	unsigned int i = 0;

	if (top == NULL || *top == NULL)
		return (-1);

	if (index == 0)
	{
		ptr = (*top);
		if ((*top)->next)
		{
			(*top)->next->prev = NULL;
			(*top) = (*top)->next;
			free(ptr);
		}
		else
		{
			*top = NULL;
			free(ptr);
		}
		return (1);
	}
	ptr = *top;
	while (ptr)
	{
		if (i == index)
		{

			ptr->prev->next = ptr->next;
			if (ptr->next)
				ptr->next->prev = ptr->prev;

			free(ptr);
			return (1);
		}
		i++;
		ptr = ptr->next;
	}
	return (-1);
}
