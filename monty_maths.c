#include "monty.h"

/**
 * add - compute the sum for the top two elements of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	char *op = "add";

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokErr(shortStackErr(line_number, op));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * sub - compute the difference for the top two elements of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	char *op = "sub";

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokErr(shortStackErr(line_number, op));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop(stack, line_number);
}
