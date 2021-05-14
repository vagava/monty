#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack.
 *@header: pointer to stack
 *@line_number: current line
 * Return: Nothing.
 */

void f_swap(stack_t **header, unsigned int line_number)
{
	stack_t *top = NULL;

	if (!*header || !(*header)->next)
		exit_error_function("can't swap, stack too short", line_number);

	top = *header;
	top = top->next;
	if (top->next)
	{
		top->next->prev = top->prev;
		top->prev->next = top->next;
	}
	else
		top->prev->next = NULL;
	top->prev->prev = top;
	top->next = top->prev;
	top->prev = NULL;
	*header = top;
}
/**
 * f_add - adds the top two elements of the stack.
 *@header: pointer to stack
 *@line_number: current line
 * Return: Nothing.
 */
void f_add(stack_t **header, unsigned int line_number)
{
	stack_t *result = NULL;
	int new_n = 0;

	if (!*header || !(*header)->next)
		exit_error_function("can't add, stack too short", line_number);

	result = (*header)->next;
	new_n = (*header)->n + result->n;
	result->n = new_n;
	*header = result;
	free(result->prev);
	result->prev = NULL;

}
/**
 * f_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 *@header: pointer to stack
 *@line_number: current line
 * Return: Nothing.
 */
void f_sub(stack_t **header, unsigned int line_number)
{
	stack_t *result = NULL;
	int new_n = 0;

	if (!*header || !(*header)->next)
		exit_error_function("can't sub, stack too short", line_number);

	result = (*header)->next;
	new_n = result->n - (*header)->n;
	result->n = new_n;
	*header = result;
	free(result->prev);
	result->prev = NULL;
}
/**
 * f_div -  divides the second top element
 * of the stack by the top element of the stack.
 *@header: pointer to stack
 *@line_number: current line
 * Return: Nothing.
 */
void f_div(stack_t **header, unsigned int line_number)
{
	stack_t *result = NULL;
	int new_n = 0;

	if (!*header || !(*header)->next)
		exit_error_function("can't div, stack too short", line_number);
	result = (*header)->next;
	if (result->prev->n == 0)
		exit_error_function("division by zero", line_number);
	new_n = result->n / (*header)->n;
	result->n = new_n;
	*header = result;
	free(result->prev);
	result->prev = NULL;
}
