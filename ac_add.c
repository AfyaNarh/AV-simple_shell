#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the head (top) of the stack.
 * @line_number: The line number in the file where the "add" opcode is encountered.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->n) + ((*stack)->next->n);

	pop(stack, line_number);
	(*stack)->n = result;
}
