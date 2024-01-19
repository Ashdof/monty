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
		return (mallocErr());

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

/**
 * check_mode - check the mode of the stack
 * @stack: a pointer to the top (stack) or bottom (queue)
 * of stack_t linked list
 *
 * Return: 0 for stack mode, 1 for queue mode and 2 otherwise
 */
int checkMode(stack_t *stack)
{
	if (stack->n == INIT_STACK)
		return (INIT_STACK);
	else if (stack->n == INIT_QUEUE)
		return (INIT_QUEUE);
	return (2);
}
