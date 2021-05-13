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
	free_and_close();
	exit(EXIT_FAILURE);
}
/**
 * free_and_close - fee memory and close the file
 * Return: Nothing.
 */
void free_and_close(void)
{
	if (global.head)
	{
		while (global.head->next)
		{
			global.head = global.head->next;
			free(global.head->prev);
		}
	}
	free(global.head);
	free(global.line);
	if (global.file)
		fclose(global.file);
}
