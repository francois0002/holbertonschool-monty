#include "monty.h"

/**
* function_push - Add a new node at the end of a stack_t list.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

void function_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->next = NULL;

	if (temp == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new->prev = temp;
		temp->next = new;
	}
}

/**
* function_pall - Print all the elements of a stack_t list.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

void function_pall(stack_t **stack, __attribute__((unused))unsigned int
line_number)
{
	if (*stack != NULL)
	{
		stack_t *temp = *stack;

	/* go to the end of stack*/
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	/* print the first of stack*/
		while (temp->prev != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
		printf("%d\n", temp->n);
	}
}

/**
* function_pint - Print the value at the top of the stack.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

void function_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp = *stack;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		printf("%i\n", temp->n);
	}
}

/**
* function_pop - Remove the top element of the stack.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

void function_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		stack_t *temp = *stack;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		if (temp->prev != NULL)
		{
			temp->prev->next = NULL;
		}
		else
		{
			*stack = NULL;
		}

		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* function_swap - Swap the top two elements of the stack.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

void function_swap(stack_t **stack, unsigned int line_number)
{
	int temp_value;
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

	temp_value = temp->prev->n;
	temp->prev->n = temp->n;
	temp->n = temp_value;
}
