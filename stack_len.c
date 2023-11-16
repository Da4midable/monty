#include "monty.h"

/**
 * stack_len - counts the elements of a doubly linked list
 * @stack: is the pointer to the head node
 * Return: count.
 */

size_t stack_len(stack_t *stack)
{
	size_t count = 0;
	stack_t *current = stack;

	while (current != NULL)
	{

		current = current->next;
		count++;

	}

	return (count);
}
