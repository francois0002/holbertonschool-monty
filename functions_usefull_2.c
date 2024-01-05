#include "monty.h"

/**
* function_add - Add the top two elements of the stack.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

void function_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->prev->n += temp->n;

	function_pop(stack, line_number);
}

/**
* function_nop - Doesn't do anything.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

void function_nop(__attribute__((unused))stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	return;
}
