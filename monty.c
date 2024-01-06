#include "monty.h"

stack_t *g_stack = NULL;

/**
* push - pushes an element onto the stack.
* @stack: Double pointer to the beginning of the stack.
* @value: The value to push onto the stack.
*
* Description: Allocates a new node and pushes it onto the stack.
*/
void push(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
{
(*stack)->prev = new_node;
}

*stack = new_node;
printf("push %d$\n", value);
}

/**
* pall - Prints all values on the stack.
* @stack: Double pointer to the beginning of the stack.
*
* Description: Prints each element in the stack.
*/
void pall(stack_t **stack)
{
stack_t *current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
* main - Entry point
*
* Description: Demonstrates the usage of push and pall operations.
*/
int main()
{
push(&g_stack, 1);
push(&g_stack, 2);
push(&g_stack, 3);
printf("pall$\n");

pall(&g_stack);

while (g_stack != NULL)
{
stack_t *temp = g_stack;
g_stack = g_stack->next;
free(temp);
}
return (0);
}
