#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty script where opcode appears.
 * Return: EXIT_SUCCESS.
 */

int rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return (EXIT_SUCCESS);

	first = *stack;
	second = first->next;
	last = first;

	while (last->next != NULL)
		last = last->next;

	first->next = NULL;
	last->next = first;
	second->prev = NULL;
	*stack = second;

	return (EXIT_SUCCESS);
}
