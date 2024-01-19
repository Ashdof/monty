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

/**
 * pstr - print the string from the top of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack)->next;

	(void)line_number;
	while (p && p->n != 0 && (p->n > 0 && p->n <= 127))
	{
		printf("%c", p->n);
		p = p->next;
	}

	printf("\n");
}

/**
 * rotl - rotate the stack to the top
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	(void)line_number;
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
}
