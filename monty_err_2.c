#include "monty.h"

/**
 * pcharErr - print error message related to pchar opcode
 * @line_number: the line number value
 * @msg: a pointer to the message
 *
 * Return: Always EXIT_FAILURE
 */
int pcharErr(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}
