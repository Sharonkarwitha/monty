#include "monty.h"

/**
 * f_push - Adds a node to the stack
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	/* Check if argument exists */
	if (bus.arg)
	{
		/* Handle negative numbers */
		if (bus.arg[0] == '-')
			j++;

		/* Validate argument as integer */
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > '9' || bus.arg[j] < '0')
				flag = 1;
		}

		/* Exit if argument is not a valid integer */
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Exit if no argument is provided */
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Convert argument to integer */
	n = atoi(bus.arg);

	/* Add node to stack or queue depending on the mode */
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
