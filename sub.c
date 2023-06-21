#include "monty.h"

/**
 * f_sub - Subtracts the top two elements of the stack
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int difference, num_nodes;

	aux = *head;

	/* Count the number of nodes in the stack */
	for (num_nodes = 0; aux != NULL; num_nodes++)
		aux = aux->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = *head;
	difference = aux->next->n - aux->n;
	aux->next->n = difference;
	*head = aux->next;
	free(aux);
}
