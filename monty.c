#include "monty.h"
/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array containing command-line arguments
 *
 * This function checks for the correct number of arguments, opens the Monty
 * bytecode file, reads and processes each line using process_line function,
 * and handles errors if encountered during file processing.
 *
 * Return: EXIT_SUCCESS upon successful execution, EXIT_FAILURE if an
 * error occurs
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1; /* Counter for line number */
	FILE *file;

	stack_t *stack = NULL;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
	/* Remove trailing newline character */
	if (line[read - 1] == '\n')
	{
	line[read - 1] = '\0';
	}

	process_line(line, &stack, line_number); /* Pass line number to function */
	line_number++;
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}

