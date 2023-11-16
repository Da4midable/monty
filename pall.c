#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
