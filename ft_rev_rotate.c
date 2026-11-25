#include "push_swap.h"

// Similar to rotate_one, instead start from the bottom. Reverse all rotate_one actions.
static void rev_rotate_one(t_stack *stack)
{
    t_node  *last;

    if (stack == NULL || stack->size < 2 || stack->top == NULL || stack->bottom == NULL)
        return ;
    last = stack->bottom;
    stack->bottom = last->prev;
    stack->bottom->next = NULL;
    last->prev = NULL;
    last->next = stack->top;
    stack->top->prev = last;
    stack->top = last;
}

void    rra(t_stack *a, t_bench *bench)
{
    if (a == NULL || a->size < 2 || a->top == NULL || a->bottom == NULL)
        return ;
    rev_rotate_one(a);
    ft_putstring("rra\n");
    if (bench != NULL)
        record_op(bench, &bench->rra);
}

void    rrb(t_stack *b, t_bench *bench)
{
    if (b == NULL || b->size < 2 || b->top == NULL || b->bottom == NULL)
        return ;
    rev_rotate_one(b);
    ft_putstring("rrb\n");
    if (bench != NULL)
        record_op(bench, &bench->rrb);
}

void    rrr(t_stack *a, t_stack *b, t_bench *bench)
{
    int can_rev_a;
    int can_rev_b;

    can_rev_a = (a != NULL && a->size >= 2 && a->top != NULL && a->bottom != NULL);
    can_rev_b = (b != NULL && b->size >= 2 && b->top != NULL && b->bottom != NULL);
    if (can_rev_a == 0 && can_rev_b == 0)
        return ;
    if (can_rev_a != 0)
        rev_rotate_one(a);
    if (can_rev_b != 0)
        rev_rotate_one(b);
    ft_putstring("rrr\n");
    if (bench != NULL)
        record_op(bench, &bench->rrr);
}