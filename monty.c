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
	FILE *fd;
	char *buffer = NULL, **tks = NULL;
	size_t size = 0;
	ssize_t nchar = 0;
	int line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nchar = getline(&buffer, &size, fd)) != -1)
	{
		tks = line_split(buffer, " \n");
		handler(tks, line_num, fd, buffer);
		line_num++;
		free_2D(tks, ntok(tks));
	}
	fclose(fd);
	free(buffer);
	free_stack();
	return (EXIT_SUCCESS);
}

/**
 * handler - handles the different commands
 * @tks: tokenized line
 * @line_num: line number
 * @fd: file pointer
 * @buffer: buffer where the read line is stored
 */
void handler(char **tks, int line_num, FILE *fd, char *buffer)
{
	if (strcmp(tks[0], "push") == 0)
	{
		if (ntok(tks) < 2 || (atoi(tks[1]) == 0 && strcmp(tks[1], "0")))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(fd);
			free(buffer);
			free_stack();
			free_2D(tks, ntok(tks));
			exit(EXIT_FAILURE);
		}
		else
			push_fun(atoi(tks[1]));
	}
	else if (strcmp(tks[0], "pall") == 0)
		pall_fun();
	else
	{
	}
}
