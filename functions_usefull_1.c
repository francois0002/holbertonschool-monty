#include "monty.h"

/**
* function_push - Add a new node at the end of a stack_t list.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

int function_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		return (NULL);
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

	return (0);
}

/**
* function_pall - Print all the elements of a stack_t list.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

int function_pall(stack_t **stack, __attribute__((unused))unsigned int
line_number)
{
	if (*stack != NULL)
	{
		stack_t *temp = *stack;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		while (temp->prev != NULL)
		{
			printf("%i\n", temp->n);
			temp = temp->prev;
		}
	}

	return (0);
}

/**
* function_pint - Print the value at the top of the stack.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

int function_pint(stack_t **stack, __attribute__((unused))unsigned int
line_number)
{
	if (*stack != NULL)
	{
		printf("L<line_number>: can't pint, stack empty\n");
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
		return (0);
	}
}

/**
* function_pop - Remove the top element of the stack.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

int function_pop(stack_t **stack, __attribute__((unused))unsigned int
line_number)
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
		return (0);
	}
	else
	{
		printf("L<line_number>: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
}

/**
* function_swap - Swap the top two elements of the stack.
* @stack: pointer to the head of a stack_t list.
* @line_number: line number of the opcode.
* Return: 0 on success.
*/

int function_swap(stack_t **stack, __attribute__((unused))unsigned int
line_number)
{
	int temp_value;
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp_value = temp->prev->n;
	temp->prev->n = temp->n;
	temp->n = temp_value;

	return (0);
}
