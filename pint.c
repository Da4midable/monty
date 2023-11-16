#include "monty.h"

/**
 * pint - Print the value at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty script where the opcode appears.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
