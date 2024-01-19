#include "monty.h"

/**
 * opCodeErr - print error message related to instructions
 * @line: the line number
 * @opcode: a pointer to the opcode
 *
 * Return: Always EXIT_FAILURE
 */
int opCodeErr(unsigned int line, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
	return (EXIT_FAILURE);
}
