#include "monty.h"

/**
 * pop - removes value at the top of the stack.
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where the opcode appears.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(current);
}
