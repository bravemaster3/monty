#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t all_ops[];

void push_fun(stack_t **stack, unsigned int line_number);
void pall_fun(stack_t **stack, unsigned int line_number);
void add_fun(stack_t **stack, unsigned int line_number);

/*char **line_split(char *buff, char *delim);*/
/*int ntok(char **toks);*/
/*void free_2D(char **grd, int n_rows);*/
void free_stack(stack_t *top);
void free_and_exit(stack_t *top, FILE *fp, instruction_t *instr);
int is_valid_integer(char *str);
void handler(stack_t **top, instruction_t *instr, int lnum, FILE *fp);
int stack_len(stack_t *top);
int del_at_indx(stack_t **top, unsigned int index);

#endif /* MONTY_H */
