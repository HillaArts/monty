#include "monty.h"
/**
 * process_line - Processes each line from the bytecode file
 * @line: Line containing the opcode and its arguments
 * @stack: Pointer to the doubly linked list representing the stack
 * @line_number: Line number in the bytecode file being processed
 *
 * This function processes each line read from the bytecode file.
 * It executes the corresponding opcode and performs necessary operations.
 */

void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int value;

	opcode = strtok(line, " \n\t\r");

	if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
	{
	return; /* Empty line or comment, skip */
	}

	if (strcmp(opcode, "push") == 0)
	{
	char *arg = strtok(NULL, " \n\t\r");

	if (arg == NULL)
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	push(stack, value); /* Implement push logic */
	}
	else if (strcmp(opcode, "pall") == 0)
	{
	pall(stack); /* Implement pall logic */
	}
	else
	{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
	}
}

