#include "monty.h"

/**
 * divvy - divides the second top element of stack by top element of stack.
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where opcode appears.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int divvy(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;
	int div_int;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current->next;
	div_int = temp->n / current->n;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
	}
	current->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = current;
	}

	free(temp);


	current->n = div_int;

	return (EXIT_SUCCESS);
}
