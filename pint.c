#include "monty.h"

/**
 * f_pint - prints the top element of the stack
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
		exit_with_error("L%u: can't pint, stack empty", head, counter);

	printf("%d\n", (*head)->n);
}
