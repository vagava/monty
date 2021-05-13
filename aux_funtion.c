#include "monty.h"

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
	free_and_close();
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
