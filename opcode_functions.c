#include "monty.h"
stack_t *stack = NULL;
/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 *
 * This function adds a new node with the given value to the top of the stack.
 * It allocates memory for a new node and handles the necessary linking.
 */
void push(stack_t **stack, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        print_malloc_error();
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
 * pall - Prints all elements in the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
 *
 * This function prints all the elements present in the stack from top to bottom.
 */
void pall(stack_t **stack) {
    stack_t *current = *stack;
    if (current == NULL) {
        return;
    }

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

