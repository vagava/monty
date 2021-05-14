#include "monty.h"
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
/**
 * f_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 *@header: pointer to stack
 *@line_number: current line
 * Return: Nothing.
 */
void f_mul(stack_t **header, unsigned int line_number)
{
	stack_t *result = NULL;
	int new_n = 0;

	if (!*header || !(*header)->next)
		exit_error_function("can't mul, stack too short", line_number);
	result = (*header)->next;
	new_n = result->n * (*header)->n;
	result->n = new_n;
	*header = result;
	free(result->prev);
	result->prev = NULL;
}
/**
 * f_mod - computes the rest of the division
 * of the second top element of the stack by
 * the top element of the stack.
 *@header: pointer to stack
 *@line_number: current line
 * Return: Nothing.
 */
void f_mod(stack_t **header, unsigned int line_number)
{
	stack_t *result = NULL;
	int new_n = 0;

	if (!*header || !(*header)->next)
		exit_error_function("can't mod, stack too short", line_number);
	result = (*header)->next;
	if (result->prev->n == 0)
		exit_error_function("division by zero", line_number);
	new_n = result->n % (*header)->n;
	result->n = new_n;
	*header = result;
	free(result->prev);
	result->prev = NULL;
}
