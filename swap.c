#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where the opcode appears.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp;
	int len = stack_len(*stack);

	if (*stack == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp = current->next;
	current->next = temp->next;
	current->prev = temp;

	if (temp != NULL)
	{
		temp->next->prev = current;
	}
	temp->next = current;
	temp->prev = NULL;

	*stack = temp;
	return (EXIT_SUCCESS);
}
