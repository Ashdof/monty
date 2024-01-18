#include "monty.h"

/**
 * initStack - initialize a stack
 * @stack: a reference pointer to the stack
 *
 * Return: 0 on success, 1 otherwise
 */
int initStack(stack_t **stack)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	node->prev = NULL;
	node->n = INIT_STACK;
	node->next = NULL;
	*stack = node;

	return (EXIT_SUCCESS);
}

/**
 * freeStack - free the stack
 * @stack: a reference pointer to the stack
 *
 * Return: nothing
 */
void freeStack(stack_t **stack)
{
	stack_t *p = *stack;

	while (*stack)
	{
		p = (*stack)->next;
		free(*stack);
		*stack = p;
	}
}
