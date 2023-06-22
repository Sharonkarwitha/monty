#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, temp;

	h = *head;

	/* Count the number of nodes in the stack */
	while (h)
	{
		h = h->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
