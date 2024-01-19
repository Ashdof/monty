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
		status = usageErr();
		return (status);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		status = openFileErr(argv[1]);
		return (status);
	}
	status = parse(file);
	fclose(file);

	return (status);
}
