#include "monty.h"

/**
*get_fonctions - function pointer between the command and the good function
*
*@command: pointer contain command associate to function
*
*Return: NULL
*/

int (*get_fonctions(char *command))(stack_t **stack, unsigned int line_number)
{
	instruction_t fonction_pointeur[] = {
		{"push", function_push},
		{"pall", function_pall},
		{"pint", function_pint},
		{"pop", function_pop},
		{"swap", function_swap},
		{"add", function_add},
		{"nop", function_nop},
		{NULL, NULL}
	};
	int index = 0;

	while (fonction_pointeur[index].opcode != NULL)
	{
		if (strcmp(fonction_pointeur[index].opcode, command) == 0)
		{
			return (fonction_pointeur[index].f);
		}
		index++;
	}
	return (NULL);
}
