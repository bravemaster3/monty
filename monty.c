#include "monty.h"

stack_t *top = NULL;

/**
 * main - entry point of the monty program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *buffer = NULL, **tks = NULL;
	size_t size = 0;
	ssize_t nchar = 0;
	int line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nchar = getline(&buffer, &size, fp)) != -1)
	{
		tks = line_split(buffer, " \n");
		handler(tks, line_num, fp, buffer);
		line_num++;
		free_2D(tks, ntok(tks));
	}
	fclose(fp);
	free(buffer);
	free_stack();
	return (EXIT_SUCCESS);
}

/**
 * handler - handles the different commands
 * @tks: tokenized line
 * @line_num: line number
 * @fp: file pointer
 * @buffer: buffer where the read line is stored
 */
void handler(char **tks, int line_num, FILE *fp, char *buffer)
{
	if (strcmp(tks[0], "push") == 0)
	{
		if (ntok(tks) < 2 || (atoi(tks[1]) == 0 && strcmp(tks[1], "0")))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_and_exit(fp, buffer, tks);
		}
		else
			push_fun(atoi(tks[1]));
	}
	else if (strcmp(tks[0], "pall") == 0)
		pall_fun();
	else if (strcmp(tks[0], "pint") == 0)
	{
		if (top == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
			free_and_exit(fp, buffer, tks);
		}
		else
			pint_fun();
	}
	else if (strcmp(tks[0], "pop") == 0)
	{
		if (top == NULL)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
			free_and_exit(fp, buffer, tks);
		}
		else
			pop_fun();
	}
	else if (strcmp(tks[0], "swap") == 0)
	{
		if (stack_len() < 2)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
			free_and_exit(fp, buffer, tks);
		}
		else
			swap_fun();
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, buffer);
		free_and_exit(fp, buffer, tks);
	}
}

	/**
	 * free_and_exit - frees allocd spaces and exits with EXITFAILURE
	 * @tks: tokenized line
	 * @fp: file pointer
	 * @buffer: buffer where the read line is stored
	 */
	void free_and_exit(FILE *fp, char *buffer, char **tks)
	{
		fclose(fp);
		free(buffer);
		free_stack();
		free_2D(tks, ntok(tks));
		exit(EXIT_FAILURE);
	}
