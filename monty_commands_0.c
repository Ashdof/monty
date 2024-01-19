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

/**
 * pint - print the first element at the top of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		setOpTokErr(pintErr(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * pop - remove the top element of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p = NULL;

	if ((*stack)->next == NULL)
	{
		setOpTokErr(popErr(line_number));
		return;
	}

	p = (*stack)->next->next;
	free((*stack)->next);
	if (p)
		p->prev = *stack;
	(*stack)->next = p;
}

/**
 * swap - swap the top two elements of the stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	char *op = "swap";

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokErr(shortStackErr(line_number, op));
		return;
	}

	p = (*stack)->next->next;
	(*stack)->next = p->next;
	(*stack)->next->prev = p;
	if (p->next)
		p->next->prev = (*stack)->next;
	p->next = (*stack)->next;
	p->prev = *stack;
	(*stack)->next = p;
}
