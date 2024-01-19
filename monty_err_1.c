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

/**
 * pintErr - print error message related to pint opcode
 * @line_number: the line number value
 *
 * Return: Always EXIT_FAILURE
 */
int pintErr(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * popErr - print error message related to pop opcode
 * @line_number: the line number value
 *
 * Return: Always EXIT_FAILURE
 */
int popErr(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack", line_number);
	return (EXIT_FAILURE);
}
