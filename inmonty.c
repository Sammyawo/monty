#include "monty.h"

/**
 * in_monty - Monty Interpreter
 * @av: argument vector
 * Return: nothing
 */

void in_monty(char **av)
{
	char *file = av[1], *buffer = NULL, **tokens = NULL;
	size_t len = 0, inu = 1;
	ssize_t r_line;

	stack_t *st_stack = NULL;
	FILE *open_f;

	open_f = fopen(file, "r");
	if (open_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	for (inu = 1; (r_line = getline(&buffer, &len, open_f)) != -1; inu++)
	{
		token_line(&buffer, &tokens, r_line);
		if (tokens != NULL)
			opcode_choose(&st_stack, &tokens, inu);
		freetokens(&tokens);
	}

	fclose(open_f);
	if (buffer != NULL)
		free(buffer);
	rest_stack(t_stack);
}

/**
 * freetokens - Free the tokens
 * @tokens: tokens to free
 * Return: nothing
 */

void freetokens(char ***tokens)
{
	if (*tokens != NULL)
	{
		free(*tokens);
		*tokens = NULL;
	}
}

/**
 * rest_stack - Free the stack
 * @t_stack: Stack to free
 * Return: nothing
 */

void rest_stack(stack_t *t_stack)
{
	stack_t *savepoin;

	if (t_stack != NULL)
	{
		while (t_stack != NULL)
		{
			savepoin = t_stack->next;
			free(t_stack);

			t_stack = savepoin;
		}
	}

}
