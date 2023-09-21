#include "monty.h"

instruction_t all_ops[] = {
	{"push", push_fun},
	{"pall", pall_fun},
	{"add", add_fun},
	{"swap", swap_fun},
	{"pint", pint_fun},
	{"pop", pop_fun},
	{"nop", nop_fun},
	{"sub", sub_fun},
	{"mul", mul_fun},
	{"div", div_fun},
	{"mod", mod_fun},
	{"pchar", pchar_fun},
	{"pstr", pstr_fun},
	{"rotl", rotl_fun},
	{"rotr", rotr_fun},
	{NULL, NULL}};

/**
 * main - entry point of the monty program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t size = 0;
	ssize_t nchar = 0;
	int line_num = 1;
	instruction_t *instr;
	stack_t *top = NULL;

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
	instr = malloc(sizeof(instruction_t));
	if (instr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	instr->opcode = NULL;
	while ((nchar = getline(&(instr->opcode), &size, fp)) != -1)
	{
		handler(&top, instr, line_num, fp);
		line_num++;
	}
	fclose(fp);
	free(instr->opcode); /* important */
	free(instr);
	free_stack(top);
	return (EXIT_SUCCESS);
}

/**
 * handler - handles the different commands
 * @top: pointer to pointer to the top of the stack
 * @instr: instruction
 * @lnum: line number
 * @fp: file pointer
 */
void handler(stack_t **top, instruction_t *instr, int lnum, FILE *fp)
{
	char *cpy_instr = strdup(instr->opcode);
	char *cmd = strtok(instr->opcode, " \n");
	int i = 0, command_found = 0;

	errno = 0;
	if (cmd == NULL)
	{
		errno = -998;
		free(cpy_instr);
	}
	else if (*cmd == '#')
		free(cpy_instr);
	else
	{
		while (all_ops[i].opcode != NULL)
		{
			if (strcmp(cmd, all_ops[i].opcode) == 0)
			{
				command_found = 1;
				all_ops[i].f(top, lnum);
				free(cpy_instr);
				free_and_exit(*top, fp, instr);
			}
			i++;
		}
		if (command_found == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s", lnum, cpy_instr);
			errno = -999;
			free(cpy_instr);
			free_and_exit(*top, fp, instr);
		}
	}
}
