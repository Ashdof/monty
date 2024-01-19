#include "monty.h"

/**
 * fillNumbaseBuff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void fillNumbaseBuff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
 * _stack - convert a queue to a stack
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(*stack)->n = INIT_STACK;
}

/**
 * _queue - convert a stack to a queue
 * @stack: a reference pointer to the stack
 * @line_number: the line number value
 *
 * Return: nothing
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(*stack)->n = INIT_QUEUE;
}
