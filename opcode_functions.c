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
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Function to remove the top element of the stack
 * @stack: Pointer to the stack
 */
void pop(stack_t **stack)
{
	if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }

    free(temp);
}

/**
 * swap - Function to swap the top two elements of the stack
 * @stack: Pointer to the stack
 */
void swap(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    int temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - Function to add the top two elements of the stack
 * @stack: Pointer to the stack
 */
void add(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack);
}

/**
 * nop - Function for the nop opcode
 * @stack: Pointer to the stack
 */
void nop(stack_t **stack) {
	/* The nop opcode doesn't perform any action,
     * so the function body remains empty */
}

/**
 * sub - Function to subtract the top element from the second top element
 * @stack: Pointer to the stack
 */
void sub(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack);
}

/**
 * div_op - Function to divide the second top element by the top element
 * @stack: Pointer to the stack
 */
void div_op(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack);
}

/**
 * mul - Function to multiply the top two elements of the stack
 * @stack: Pointer to the stack
 */
void mul(stack_t **stack) {
	 if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    pop(stack);
}

