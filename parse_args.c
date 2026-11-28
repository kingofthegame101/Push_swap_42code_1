#include "push_swap.h"

// Guard Check. Followed by checking if the sign is '+' or '-' and changing the sign upon return.
// We want to amend the original pointer value of i so that it can move.
static int  parse_sign(const char *s, int *i)
{
    if (s == NULL || i == NULL)
        return (1);
    if (s[*i] == '+' || s[*i] == '-')
    {
        if (s[*i] == '-')
        {
            (*i)++;
            return (-1);
        }
        (*i)++;
    }
    return (1);
}

// Guard checks. Followed by ensuring that it is a value. If the final vlaue is outside the limits
// reject it. The pointer out carries the actual value while the function returns a boolean value,
// of 0 or 1. (Did not use value again to prevent confusion with struct value)
static int  parse_int_inputs(const char *s, int *out)
{
    long    val;
    int     sign;
    int     i;

    if (s == NULL || out == NULL || s[0] == '\0')
        return (0);
    i = 0;
    sign = parse_sign(s, &i);
    if (s[i] < '0' || s[i] > '9')
        return (0);
    val = 0;
    while (s[i] >= '0' && s[i] <= '9')
    {
        val = val * 10 + (s[i] - '0');
        if ((sign == 1 && val > INT_MAX) || (sign == -1 && -val < INT_MIN))
            return (0);
        i++;
    }
    if (s[i] != '\0')
        return (0);
    *out = (int)(val * sign);
    return (1);
}

// Guard check. Next, set the current node to the stack->top. Then it iterates through the stack
// comparing the current stack's value with the value in question. If match found, return boolean
// of 1, else return 0, no match. If not continue iterating till the end of the stack.
static int  is_duplicate(t_stack *stack, int value)
{
    t_node  *current;

    if (stack == NULL)
        return (0);
    current = stack->top;
    while (current != NULL)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}

// Tokens are the char str provided by the argv, before it is converted into an integer.
// Freeing is to prevent memory leaks. Free each token[i] (values) before free token
// to ensure that pointer to each token[i] is not lost before they are freed.
void free_tokens(char **tokens)
{
    int i;

    if (token == NULL)
        return ;
    i = 0;
    while (tokens[i] != NULL)
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

// This function is to return a boolean of whether all the tokens in this argument are
// (1) valid integers, (2) unique, no duplicates, (3) can it be added to the stack.
// The while loop refers to a pointer to a char *, hence != NULL
int process_tokens(char **tokens, t_stack *stack)
{
    int i;
    int nbr;

    i = 0;
    while (tokens[i] != NULL)
    {
        if (parse_int_inputs(tokens[i], &nbr) == 0)
            return (0);
        if (is_duplicate(stack, nbr))
            return (0);
        if (stack_append(stack, nbr) == 0)
            return (0);
        i++;
    }
    return (1);
}
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
