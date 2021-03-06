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
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"sub", f_sub}, {"div", f_div}, {"nop", NULL},
		{"mul", f_mul}, {"mod", f_mod}, {"pchar", pchar},
		{"pstr", pstr},
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
