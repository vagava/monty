#include "monty.h"
/**
 * converter_to_number - converter a str in integer
 * @token: opcode instruction to search
 * @line_number: current line
 * @function: function to compare
 * Return: Nothing.
 */
int converter_to_number(char *token, unsigned int line_number,
			op_function function)
{
	char *search;
	int n = 0;
	bool is_num = true;

	if (function != f_push) /*a function whit out arguments*/
		return (line_number);

	if (token == NULL)
		exit_error_function("usage: push integer", line_number);
	search = token;
	while (*token)
	{
		if (*token == '-')
			token++;
		if (*token < '0' || *token > '9')
		{
			is_num = false;
			break;
		}
		token++;
	}
	if (is_num == false)
		exit_error_function("usage: push integer", line_number);

	n = atoi(search);
	return (n);
}
