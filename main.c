#include "monty.h"

/**
 * main - entry point for the Monty interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024], *opcode, *arg;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL || (!isdigit(*arg) && *arg != '-'))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(arg), line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}

		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}

		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}

		else if (strcmp(opcode, "swap") == 0)
		{
			if (stack_len(stack) < 2)
			{
				fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			swap(&stack, line_number);
		}

		else if (strcmp(opcode, "add") == 0)
		{
			if (stack_len(stack) < 2)
			{
				fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			add(&stack, line_number);
		}

		else if (strcmp(opcode, "nop") == 0)
		{
			;
		}

		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
