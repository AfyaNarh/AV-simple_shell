#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: The line number in the file where the "swap"
 * opcode is encountered.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first_node, *second_node;
	int teemp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%u -tack too short to perform swap\n", line_number);
		exit(EXIT_FAILURE);
	}

	first_node = *stack;
	second_node = (*stack)->next;

	temp = first_node->n;
	first_node->n = second_node->n;
	second_node->n = temp;
}
