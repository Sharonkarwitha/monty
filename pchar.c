#include "monty.h"

/**
 * exit_with_error - Handles error conditions and exits the program
 * @message: Error message to print
 * @head: Stack head
 */
void exit_with_error(const char *message, stack_t **head)
{
	fprintf(stderr, "%s\n", message);
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}

/**
 * f_pchar - prints the char at the top of the stack, followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
		exit_with_error("L%d: can't pchar, stack empty", head, counter);

	if (h->n > 127 || h->n < 0)
		exit_with_error("L%d: can't pchar, value out of range", head, counter);

	printf("%c\n", h->n);
}
