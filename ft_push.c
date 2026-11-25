#include "push_swap.h"

// Guard check. If source or dest stack is empty, or source->size is empty or sorce->top is empty
// Using the following eg. stack a = [10, 20, 30], size = 3 and stack b = [], size = 0.
// Set node as source->top, i.e. node = [10] from stack a.
// stack a new top node = [20]. Since stack a's original size = 3, change [20] to NULL
// else, if stack a's original size was 1, removing 1 node means new bottom = NULL.
// stack a's size to reduce by 1
// Set node [10] prev to NULL and connect stack b's top->previous to node
// If stack b is not empty, connect the previous stack b's top->previous to node [10]
// else node [10] becomes stack b's new bottom as well
// Lastly, set node as stack b's new top and increase stack b's size
static void push_top(t_stack *src, t_stack *dest)
{
    t_node  *node;

    if (src == NULL || dest == NULL || src->size == 0 || src->top == NULL)
        return ;
    node = src->top;
    src->top = node->next;
    if (src->top != NULL)
        src->top->prev = NULL;
    else
        src->bottom = NULL;
    src->size--;
    node->prev = NULL;
    node->next = dest->top;
    if (dest->top != NULL)
        dest->top->prev = node;
    else
        dest->bottom = node;
    dest->top = node;
    dest->size++;
}

// Guard check, then execute push_top function. Print action. Lastly update operation count.
void    pa(t_stack *a, t_stack *b, t_bench *bench)
{
    if (a == NULL || b == NULL || b->size == 0 || b->top == NULL)
        return ;
    push_top(b, a);
    ft_putstring("pa\n");
    if (bench != NULL)
        record_op(bench, &bench->pa);
}

void    pb(t_stack *a, t_stack *b, t_bench *bench)
{
    if (a == NULL || b == NULL || a->size == 0 || a->top == NULL)
        return ;
    push_top(a, b);
    ft_putstring("pb\n");
    if (bench != NULL)
        record_op(bench, &bench->pb);
}
