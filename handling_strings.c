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
	if (top->n <= 32 || top->n >= 126)
		exit_error_function("can't pchar, value out of range", line_number);
	printf("%c\n", top->n);
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @header: opcode instruction to search
 * @line_number: current line
 * Return: Nothing.
 */
void pstr(stack_t **header, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = NULL;

	if (!*header)
	{
		printf("%c", 10);
		return;
	}
	top = *header;
	while (top)
	{
		if (top->n <= 32 || top->n >= 126 || top->n == 0)
			break;
		printf("%c", top->n);
		if (!top->next)
			break;
		top = top->next;
	}
	printf("%c", 10);
}
