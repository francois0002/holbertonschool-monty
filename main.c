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
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	int (*function_ptr)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
    /* Open the .m file*/
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
    /* Read the file line by line */
 while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        char *command = strtok(line, " \t\n");

        if (command != NULL && command[0] != '#')
        {
            function_ptr = get_fonctions(command);
            if (function_ptr == NULL)
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command);
                free(line);
                fclose(file);
                exit(EXIT_FAILURE);
            }

            function_ptr(&stack, line_number);
        }
    }

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
