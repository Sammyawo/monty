#include "monty.h"

/**
 * main - start the monty interpreter
 * @ac: argument count
 * @av: argument vector
 * Return: 0 in success exit or different to 0 in unsuccess
 */

int main(int ac, char **av)
{
	if (ac == 2)
		in_monty(av);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
