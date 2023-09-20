#include "monty.h"
/**
 * free_and_exit - frees allocd spaces and exits with EXITFAILURE
 * @top: pointer to top of the stack
 * @fp: file pointer
 * @instr: the instruction containing also the buffer read by getline
 */
void free_and_exit(stack_t *top, FILE *fp, instruction_t *instr)
{
	if (errno == -999)
	{
		fclose(fp);
		free(instr->opcode);
		free(instr);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
}
