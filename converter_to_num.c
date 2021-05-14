#include "monty.h"
/**
 * converter_to_number - converter a str in integer
 * @token: opcode instruction to search
 * @line_number: current line
 * Return: Nothing.
 */
int converter_to_number(char *token, unsigned int line_number, op_function function)
{
	int n = 0;
	if (function != f_push) /*a function whit out arguments*/
		return line_number;
	if (token == NULL)
	{
		exit_error_function("usage: push integer", line_number);
	}
	if (*token == '-' || *token < '0' || *token > '9')/*if not int or negative*/
	{
		if (*token == '-')/*if negative*/
		{
			token++;
			if (*token < '0' || *token > '9')
				exit_error_function("usage: push integer", line_number);
			else
				token--;
		}
		else /*if is a leter*/
			exit_error_function("usage: push integer", line_number);
	}
	n = atoi(token);
	return (n);
}
