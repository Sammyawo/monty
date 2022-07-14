#include "monty.h"

int num;

/**
 * pushS - push a number in a stack
 * @t_stack: The stack
 * @inu: line of code
 * Return: nothing
 */

void pushS(stack_t **t_stack, unsigned int inu)
{
	stack_t *new = malloc(sizeof(stack_t));
	(void) inu;

	if (new == NULL)
		return;

	new->n = num;
	new->prev = NULL;
	new->next = NULL;
	if (*t_stack != NULL)
	{
		new->next = *t_stack;
		(*t_stack)->prev = new;
	}
	*t_stack = new;
}

/**
 * printS - print the stack
 * @t_stack: The stack
 * @inu: line of code
 * Return: nothing
 */

void printS(stack_t **t_stack, unsigned int inu)
{
	stack_t *save = *t_stack;
	(void) inu;

	if (*t_stack == NULL)
		return;
	while (save != NULL)
	{
		printf("%d\n", save->n);
		save = save->next;
	}
}

/**
 * pintS - print the top of the stack
 * @t_stack: The stack
 * @inu: line of code
 * Return: nothing
 */

void pintS(stack_t **t_stack, unsigned int inu)
{
	if (*t_stack != NULL)
		printf("%d\n", (*t_stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", inu);
		exit(EXIT_FAILURE);
	}

}

/**
 * popS - delete the top of the stack
 * @t_stack: The stack
 * @inu: line of code
 * Return: nothing
 */

void popS(stack_t **t_stack, unsigned int inu)
{
	stack_t *save;

	if (*t_stack != NULL)
	{
		save = (*t_stack)->next;
		free(*t_stack);
		*t_stack = save;

		if (*t_stack != NULL)
			(*t_stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", inu);
		exit(EXIT_FAILURE);
	}
}

/**
 * swapS - delete the top of the stack
 * @t_stack: The stack
 * @inu: line of code
 * Return: nothing
 */

void swapS(stack_t **t_stack, unsigned int inu)
{
	stack_t *save;
	int i;

	if (*t_stack != NULL && (*t_stack)->next != NULL)
	{
		save = (*t_stack)->next;
		i = (*t_stack)->n;
		(*t_stack)->n = save->n;
		save->n = i;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", inu);
		exit(EXIT_FAILURE);
	}
}
