#include "monty.h"

/**
 * sub - subtracts top element from second top element of stack.
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where opcode appears.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;
	int sub_int;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't subt, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current->next;
	sub_int = temp->n - current->n;

	current->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = current;
	}

	free(temp);


	current->n = sub_int;

	return (EXIT_SUCCESS);
}
