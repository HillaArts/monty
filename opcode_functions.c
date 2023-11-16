#include "monty.h"
/**
 * push - Function to push an element onto the stack
 * @stack: Pointer to the stack
 * @value: Value to push onto the stack
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node; 
}

/**
 * pall - Function to print all elements on the stack
 * @stack: Pointer to the stack
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }

}
/**
 * pint - Function to print the value at the top of the stack
 * @stack: Pointer to the stack
 */
void pint(stack_t **stack)
{
	if (*stack == NULL) {
        fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
