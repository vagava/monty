#include "monty.h"
/**
 * pchar -  prints the char at the top of the stack, followed by a new line.
 * @header: opcode instruction to search
 * @line_number: current line
 * Return: Nothing.
 */
void pchar(stack_t **header, unsigned int line_number)
{
	stack_t *top = NULL;

	if (!*header)
		exit_error_function("can't pchar, stack empty", line_number);
	top = *header;
	if (top->n < 00 || top->n > 255)
		exit_error_function("can't pchar, value out of range", line_number);
	printf("%c\n", itoa(top->n));
}
