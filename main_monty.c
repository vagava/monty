#include "monty.h"

global_t global = {NULL, NULL, NULL, 0};  /*file,head,linea,n_struc*/

/**
 * main - entry point Vanessa Garcia
 * @argc: Contains the number of arguments that have been entered.
 * @argv: array of character pointers.
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	char *token = NULL;
	size_t size = 0;
	unsigned int line_number = 1;

	op_function funcion = NULL;

	if (argc != 2)
		exit_error_function("USAGE: monty file", 0);
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global.file = fopen(argv[1], "r"); /*open file*/
	if (global.file == NULL)
		exit_error_function("Error: malloc failed", 0);
	while (feof(global.file) == 0)
	{
		/*malloc line*/
		if (getline(&global.line, &size, global.file) != -1)
		{
			token = strtok(global.line, " \t\n");
			funcion = serch_opcode(token, line_number);
		if (funcion == f_pall || funcion == f_pint)
			funcion(&global.head, line_number);
		else if (funcion != NULL)
		{
			token = strtok(NULL, " \t\n");
			global.n_struc = converter_to_number(token, line_number);
			funcion(&global.head, line_number);
		}
		}
		line_number++;
	}
	free_and_close();
	return (0);
}


