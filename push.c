#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @n: value to push
 * @line_number: line number of the opcode in the Monty file
 */

void push(stack_t **stack, int n, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(void)(line_number);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
