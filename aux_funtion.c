#include "monty.h"
/**
 * exit_error_function - prints error in stderr and
 * does the necessary process to exit correctly
 * @msj_error: error message to print on screen
 * @line_error: line where the error is found
 * Return: Nothing
 */
void exit_error_function(char *msj_error, unsigned int line_error)
{
	if (line_error)
	{
		fprintf(stderr, "L%u: ", line_error);
	}
	fprintf(stderr, "%s\n", msj_error);
	exit(EXIT_FAILURE);
}

/**
 * serch_opcode - search opcode function sored in the token
 * @token: opcode instruction to search
 * @line_number: current line
 * Return: Nothing.
 */

op_function serch_opcode(char *token, unsigned int line_number)
{
	int i;

	instruction_t list_intructions[] = {
		{"push", f_push}, {"pall", f_pall},
		{NULL, NULL}};
	if (token == NULL || *token == '#')
		return (NULL);
	for (i = 0; list_intructions[i].opcode != NULL; i++)
		if (strcmp(token, list_intructions[i].opcode) == 0)
			return (list_intructions[i].f);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}

/**
 * converter_to_number - converter a str in integer
 * @token: opcode instruction to search
 * @line_number: current line
 * Return: Nothing.
 */

int converter_to_number(char *token, unsigned int line_number)
{
	int n = 0;

	if (token == NULL)
		exit_error_function("usage: push integer", line_number);
	if (*token == '-')
	{
		token++;
		if (*token < '0' || *token > '9')
			exit_error_function("usage: push integer", line_number);
		else
			token--;
	}
	n = atoi(token);
	return (n);
}
