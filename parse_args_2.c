#include "push_swap.h"

// Guard checks, malloc and NULL checks. node->value is to fill this node with int value.
// Since appending to the bottom, the new_node->next set to NULL and connect new_node->prev to stack->bottom
// If stack->bottom is not NULL, then connect the stack->bottom->next to new_node.
// If there is no bottom, i.e. stack is empty, new_node is also the new top.
// Set stack->bottom to new_node and increase stack size.
// Return boolean value for future use.
int stack_append(t_stack *stack, int value)
{
    t_node  *new_node;

    if (stack == NULL)
        return (0);
    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
        return (0);
    new_node->value = value;
    new_node->index = -1; //placeholder value. Subject to change based on disorder and ranking functions
    new_node->next = NULL;
    new_node->prev = stack->bottom;
    if (stack->bottom != NULL)
        stack->bottom->next = new_node;
    else
        stack->top = new_node;
    stack->bottom = new_node;
    stack->size++;
    return (1);
}

// Check if argv or stack are NULL, if yes, return boolean (0), FALSE
// Skips argv[0], since that is the program name
// Splits the argment according to delimiter ' '.
// Checks for failure, if yes then free_tokens.
// During the process token function, it appends to the stack if it passes the criteria
// Free all token once process is complete and repeats the process.
// Return boolean (1) TRUE if successfully completes the task.
int parse_args(int argc, char **argv, t_stack *stack)
{
    char    **tokens;
    int     i;

    if (argv == NULL || stack == NULL)
        return (0);
    i = 1;
    while (i < argc)
    {
        tokens = ft_split(argv[i], ' ');
        if (tokens == NULL || tokens[0] == NULL)
        {
            free_tokens(tokens);
            return (0);
        }
        if (process_tokens(tokens, stack) == 0)
        {
            free_tokens(tokens);
            return (0);
        }
        free_tokens(tokens);
        i++;
    }
    return (1);
}