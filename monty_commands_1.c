#include "monty.h"

/**
 * nop - do nothing
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - print the char at the top of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char *val_msg = "value out of range";
	char *emp_msg = "stack empty";

	if ((*stack)->next == NULL)
	{
		setOpTokErr(pcharErr(line_number, emp_msg));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		setOpTokErr(pcharErr(line_number, val_msg));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
