#include "monty.h"

/**
 * freeTokens - free tokens
 *
 * Return: nothing
 */
void freeTokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (; op_toks[i]; i++)
		free(op_toks[i]);
	free(op_toks);
}
