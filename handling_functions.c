#include "monty.h"
/**
 * f_push - The opcode pushes an element to the stack.
 *@header: pointer to stack
 * @line_number: current line
 * Return: Nothing.
 */

void f_push(stack_t **header, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
		exit_error_function("Error: malloc failed", line_number);

	if (*header != NULL)
		(*header)->prev = node;
	node->n = global.n_struc;
	node->prev = NULL;
	node->next = *header;
	*header = node;
}
/**
 * f_pall - The opcode prints all the values on the stack,
 * starting from the top of the stack.
 * @header: pointer to stack.
 * @line_number: current line
 * Return: Nothing.
 */
void f_pall(stack_t **header, unsigned int line_number __attribute__((unused)))
{
	stack_t *top = NULL;

	if (*header)
	{
		top = *header;
		while (top)
		{
			printf("%d\n", top->n);
			top = top->next;
		}
	}
}
/**
 * f_pint - only print the top
 * @header: pointer to stack.
 * @line_number: current line
 * Return: Nothing.
 */
void f_pint(stack_t **header, unsigned int line_number)
{
	if (!*header)
		exit_error_function("can't pint, stack empty", line_number);
	printf("%d\n", (*header)->n);
}
/**
 * f_pop -removes the top element of the stack.
 * @header: pointer to stack.
 * @line_number: current line
 * Return: Nothing.
 */
void f_pop(stack_t **header, unsigned int line_number)
{
	stack_t *to_pop = NULL;

	if (!*header || !header)
		exit_error_function("can't pop an empty stack", line_number);

	if ((*header)->next)
	{
		*header = (*header)->next;
		to_pop = (*header)->prev;
		free(to_pop);
		(*header)->prev = NULL;
	}
	else
	{
		free((*header));
		*header = NULL;
	}
}
