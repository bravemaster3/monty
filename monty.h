#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

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

extern stack_t *top;

void push_fun(int n);
void pall_fun(void);
void pint_fun();
void pop_fun();
int stack_len();
void swap_fun();

char **line_split(char *buff, char *delim);
int ntok(char **toks);
void free_2D(char **grd, int n_rows);
void free_stack(void);
void free_and_exit(FILE *fp, char *buffer, char **tks);
void handler(char **tks, int line_num, FILE *fp, char *buffer);

#endif /* MONTY_H */
