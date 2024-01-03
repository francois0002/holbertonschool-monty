#include "monty.h"

/***/

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

/***/

int function_pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
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

/***/

int function_pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
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

/***/

int function_pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
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

/***/

int function_swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
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

/***/

int function_add(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->prev->n += temp->n;

	return (function_pop(stack, line_number));
}

/***/

int function_nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	return (0);
}
