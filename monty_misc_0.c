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

/**
 * tokArrLen - compute the length of a token
 *
 * Return: length of current op_toks as int
 */
unsigned int tokArrLen(void)
{
	unsigned int len = 0;

	while (op_toks[len])
		len++;
	return (len);
}


/**
 * getInt - get a character pointer to a new string containing
 * an integer value
 * @num: value to convert to string
 *
 * Return: a pointer to the new string or NULL if it fails
 */
char *getInt(int num)
{
	unsigned int tmp;
	int len = 0;
	long num_l = 0;
	char *ret;

	tmp = _abs(num);
	len = getNumBaseLen(tmp, 10);

	if (num < 0 || num_l < 0)
		len++; /* negative sign */
	ret = malloc(len + 1); /* create new string */
	if (ret == NULL)
		return (NULL);

	fillNumbaseBuff(tmp, 10, ret, len);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @i: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * getNumBaseLen - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int getNumBaseLen(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
