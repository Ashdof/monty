#include "monty.h"

/**
  * main - entry point into the code
  * @argc: argument counter
  * @argv: argument vector
  *
  * Return: Success(Always 0)
  */

int main(int argc, char *argv[])
{
	FILE *file;
	int status = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		status = EXIT_FAILURE;
		return (status);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		status = EXIT_FAILURE;
		return (status);
	}
	status = parse(file);
	fclose(file);

	return (status);
}
