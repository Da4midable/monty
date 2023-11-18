#include "monty.h"

/**
 * mod - uniquely divides the top two elements of the stack.
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where opcode appears.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack to short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current->next;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = temp->n / current->next->n;
	current->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = current;
	}

	free(temp);
	current->n = result;

	return (EXIT_SUCCESS);
}
