#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: points to the top of the stack.
 * @line_number: line number in the Monty script where opcode appears.
 * Return: convert_int.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	(void)(line_number);


	while (temp != NULL && temp->n != 0 && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
		putchar('\n');
}
