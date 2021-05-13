#include "monty.h"
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
