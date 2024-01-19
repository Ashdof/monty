#include "monty.h"

/**
 * parse - parse a file
 * @file: a pointer to the opened file
 *
 * description: this functions accesses an opened file, reads its
 * contents and invokes an appropriate function to execute the
 * given instruction
 *
 * Return: on success, it returns EXIT_SUCCESS, ontherwise, it
 * returns EXIT_FAILURE
 */
int parse(FILE *file)
{
	stack_t *stack = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	int status = EXIT_SUCCESS;
	char *args = NULL;
	void (*op_cmd)(stack_t **, unsigned int);

	if (initStack(&stack) == EXIT_FAILURE)
	{
		status = EXIT_FAILURE;
		return (status);
	}

	while (getline(&args, &len, file) != -1)
	{
		line_number++;
		*op_toks = strtok(args, DELIMS);
		if (op_toks == NULL)
		{
			freeStack(&stack);
			status = mallocErr();
			return (status);
		}

		op_cmd = parseCmd(op_toks[0]);
		if (op_cmd == NULL)
		{
			freeStack(&stack);
			freeTokens();
			status =  opCodeErr(line_number, op_toks[0]);
			return (status);
		}
	}

	op_cmd(&stack, line_number);
	freeStack(&stack);
	free(args);

	return (status);
}

/**
 * parseCmd - select an appropriate function based on instruction
 * @opcode: the operation code to execute
 *
 * Return: nothing
 */
void (*parseCmd(char *opcode))(stack_t **, unsigned int)
{
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; cmd[i].opcode; i++)
	{
		if (strcmp(opcode, cmd[i].opcode) == 0)
			return (cmd[i].f);
	}

	return (NULL);
}
