#include "monty.h"
/**
 * line_split - tokenizes a buffer
 * @buff: the buffer
 * @delim: the delimiter
 *
 * Return: a pointer to the array of tokens...
 */
char **line_split(char *buff, char *delim)
{
	char *buff_cpy, *token, **tokens;
	int n_tok, counter;

	buff_cpy = strdup(buff);
	token = strtok(buff_cpy, delim);
	if (token == NULL)
	{
		free(buff_cpy);
		return (NULL);
	}
	n_tok = 1;
	while ((token = strtok(NULL, delim)))
		n_tok++;
	free(buff_cpy);

	tokens = (char **)malloc(sizeof(char *) * (n_tok + 1));
	if (tokens == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, delim);
	counter = 0;
	while (token)
	{
		tokens[counter] = strdup(token);
		token = strtok(NULL, delim);
		counter++;
	}
	tokens[n_tok] = NULL;
	return (tokens);
}

/**
 * ntok - counts tokens in a an array of tokens
 * @toks: pointer to the first token
 * Return: number of tokens in toks...
 */

int ntok(char **toks)
{
	int n_toks = 0;

	if (toks == NULL)
		return (0);
	while (toks[n_toks])
		n_toks++;
	return (n_toks);
}

/**
 * free_2D - frees malloced space for array of tokens
 * @grd:: pointer to first token
 * @n_rows: height of the grid
 */

void free_2D(char **grd, int n_rows)
{
	int row = 0;

	for (; row < n_rows; row++)
		free(grd[row]);
	free(grd);
}

/**
 * free_stack - frees stack before exiting
 */
void free_stack()
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
