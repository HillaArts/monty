#include "monty.h"
/**
 * print_usage_error - Print error message for incorrect command usage
 *
 * This function prints an error message indicating incorrect command usage.
 */
void print_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

/**
 * print_file_open_error - Print error message for failed file opening
 * @file: Name of the file that failed to open
 *
 * This function prints an error message indicating failure to open a file.
 */
void print_file_open_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
}
/**
 * print_unknown_instruction_error - Print error message for unknown instruction
 * @line_number: Line number where the unknown instruction appears
 * @opcode: Unknown opcode encountered
 *
 * This function prints an error message indicating an unknown instruction.
 */
void print_unknown_instruction_error(unsigned int line_number,
		const char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
}
/**
 * print_malloc_error - Prints an error message for memory allocation failure
 *
 * This function prints an error message to stderr when memory allocation fails.
 * It is used to handle cases where malloc fails to allocate memory.
 */
void print_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
}

