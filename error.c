#include "monty.h"

/* Error function for incorrect usage */
void print_usage_error(void) {
    fprintf(stderr, "USAGE: monty file\n");
}

/* Error function for file opening failure */
void print_file_open_error(const char *filename) {
    fprintf(stderr, "Error: Can't open file %s\n", filename);
}

/* Error function for unknown instruction */
void print_unknown_instruction_error(unsigned int line_number, const char *opcode) {
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
}

/* Error function for memory allocation failure */
void print_malloc_error(void) {
    fprintf(stderr, "Error: malloc failed\n");
}

