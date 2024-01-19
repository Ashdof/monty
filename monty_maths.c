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

/**
 * monty_div - compute the quotient fot the top two elements of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	char *op = "div";

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokErr(shortStackErr(line_number, op));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		setOpTokErr(divErr(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * monty_mul - compute the product for the top two elements of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	char *op = "mul";

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokErr(shortStackErr(line_number, op));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * monty_mod - compute the remainder fot the top two elements of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	char *op = "mod";

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokErr(shortStackErr(line_number, op));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		setOpTokErr(divErr(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop(stack, line_number);
}
