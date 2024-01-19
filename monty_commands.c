#include "monty.h"

/**
 * push - push a node onto the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *p;
	int i;

	(void)line_number;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		setOpTokErr(mallocErr());
		return;
	}
	if (op_toks[1] == NULL)
	{
		setOpTokErr(noIntErr(line_number));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			setOpTokErr(noIntErr(line_number));
			return;
		}
	}

	node->n = atoi(op_toks[1]);
	p = (*stack)->next;
	node->prev = *stack;
	node->next = p;
	if (p)
		p->prev = node;
	(*stack)->next = node;
}

/**
 * pall - print all values from the stack, starting from the top
 * @stack: a reference pointer to the stack
 * @line_number: line number value
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	(void)line_number;

	p = (*stack)->next;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
