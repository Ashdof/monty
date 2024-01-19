#include "monty.h"

/**
 * setOpTokErr - set the last element of op_toks to be an error
 * code
 * @err_code: an integer value to store as string in op_toks
 *
 * Return: nothing
 */
void setOpTokErr(int err_code)
{
	int i = 0, len = 0;
	char *str = NULL, **new_toks = NULL;

	len = tokArrLen();
	new_toks = malloc(sizeof(char *) * (len + 2));
	if (new_toks == NULL)
	{
		mallocErr();
		return;
	}

	while (i < len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	str = getInt(err_code);
	if (str == NULL)
	{
		free(new_toks);
		mallocErr();
		return;
	}
	new_toks[i++] = str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}

/**
 * mallocErr - print error message related to malloc
 *
 * Return: nothing
 */
int mallocErr(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * noIntErr - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int noIntErr(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * usageErr - print error message related to usage
 *
 * Return: Always EXIT_FAILURE
 */
int usageErr(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * openFileErr - print error message related to opening file
 * @args: a pointer to the name of the file
 *
 * Return: Always EXIT_FAILURE
 */
int openFileErr(char *args)
{
	fprintf(stderr, "Error: can't open file %s\n", args);
	return (EXIT_FAILURE);
}
