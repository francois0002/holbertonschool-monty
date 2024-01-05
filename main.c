#include "monty.h"
/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	unsigned int push_number;
	stack_t *stack = NULL;
	void (*function_ptr)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
    /* Open the .m file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
    /* Read the file line by lines */
	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		char *command = strtok(line, " \t\n");

		if (command != NULL && command[0] != '#')
		{
			if (strcmp(command, "push") == 0)
			{
				push_number = atoi(strtok(NULL, " \t\n"));
				if (push_number == 0)
				{
					fprintf(stderr, "L%u: USAGE: push integer\n", line_number);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				push_number = line_number;
			}

			function_ptr = get_fonctions(command);
			if (function_ptr == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}

			function_ptr(&stack, push_number);
		}
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
