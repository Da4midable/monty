#include "monty.h"

/**
 * pchar - prints the ASCII value of the value at the top of the stack
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where opcode appears.
 * Return: convert_int.
 */

char pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	char convert_int;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	if (current->n < 0 || current->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	convert_int = printf("%c\n", current->n);
	current = current->next;
	return (convert_int);
}
