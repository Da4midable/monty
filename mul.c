#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack.
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where opcode appears.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;
	int sum;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current->next;
	sum = current->n * temp->n;

	current->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = current;
	}



	current->n = sum;

	return (EXIT_SUCCESS);
}
