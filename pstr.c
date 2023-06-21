#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void) counter;

	temp = *head;

	/* Traverse the stack and print characters until a non-printable character is encountered */
	while (temp && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
